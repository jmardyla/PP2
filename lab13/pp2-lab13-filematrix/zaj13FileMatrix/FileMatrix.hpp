#pragma once

#include <iosfwd>
#include <string>
#include <cstddef> // std::size_t
#include <memory>  // std::unique_ptr
#include <fstream>
#include <iostream>


/** @file FileMatrix.hpp
    @date 16 kwietnia 2023
    @brief W ramach zadania trzeba zaimplementowac wszystkie opisane metody szablonu klasy FileMatrix.
    Do ponizszych metod **sa testy** w pliku @ref FileMatrixTests.cpp.
    FileMatrix jest szablonem klasy, dlatego też musi mieć implementacje w pliku nagłówkowym,
    oczywiście polecam dłuższych metod nie definiować w klasie, tylko pod nią.
    Jeśli by ktoś chciał mimo wszystko dokonać definicji w pliku źródłowym,
    może zastosować tzw. [Explicit instantiation definition](https://en.cppreference.com/w/cpp/language/class_template)
    **dla każdego z typów!**
**/

//#define UNDEFINED_FILE_MATRIX_ITERATOR


/** class FileMatrix
 * @brief Szablon klasy FileMatrix jest macierzą elementów o określonym typie,
 * ale trudność polega na tym, że z założenia jest ona w stanie trzymać macierz nie mieszczącą się w pamięci,
 * poprzez trzymanie wszystkich danych na dysku, a w aktualnej pamięci podręcznej jest tylko jeden rząd danych.
 * Dane trzymane na dysku są w formacie **binarnym**, w następującej formie:
 * 1. `IndexType rows_`
 * 2. `IndexType columns_`
 * 3. `T[]` - dane zależnie od ich ilości, będzie to `rows_*columns_`
 *
 * @note Można (a nawet należy) zaimplementować dodatkowe metody.
 * @note Można (a nawet wygodniej) dodać dodatkowe składowe klasy
 *       (niewykluczone użycie kwantyfikatora `mutable`)
 *
 * @tparam T typ przetrzymywany w macierzy
 * @tparam IndexType typ do indeksowania elementow, ten typ powinien byc uzyty do skladowych `rows_`, `columns_`
 *
 * @param filename_ pełna nazwa pliku (czyli wraz ze ścieżką i rozszerzeniem)
 * @param rows_ ilość rzędów w macierzy prostokątnej
 * @param columns_ ilość kolumn w macierzy prostokątnej
 * @param currentRow_ jest to ostatnio odczytywany rząd macierzy,
 *        dzięki niemu możemy ograniczyć lekko operacje dyskowe
 * @param currentRowNumber_ informacja którym rzędem jest powyższy
 * @param fileDescriptor_ deskryptor pliku o nazwie `filename_`,
 *        nie musimy za każdym razem na nowo otwierać i zamykać pliku (to trwa) **/
template<typename T, typename IndexType = std::size_t>
class FileMatrix
{
public:
    static constexpr auto extention()
    {
        return ".matrix";
    }

    /// @brief konstruktor przyjmujący nazwę pliku, wystarczy, że zapamięta on ją w zmiennej `filename_` i wyzeruje zmienne klasy
    FileMatrix(const std::string& filename): filename_(filename)
    {}

    /** @brief konstruktor przyjmujący poza nazwą pliku również informacje
     *  ile jest wierszy i kolumn, tym samym powinien on utworzyć plik
     *  i wypełnić go zawartością **/
    FileMatrix(IndexType rows, IndexType columns, const std::string& newFileNam): rows_(rows), columns_(columns), filename_(newFileNam) {
        fileDescriptor_.open(filename_, std::ios::out | std::ios::binary);

        if (!fileDescriptor_.is_open()) throw std::runtime_error("file couldn't open");

        fileDescriptor_.write(reinterpret_cast<char*>(&rows_), sizeof(IndexType));
        fileDescriptor_.write(reinterpret_cast<char*>(&columns_), sizeof(IndexType));

//        currentRow_.reset(new T[this->columns_]);
        T zero = 0;
        for(size_t i=0 ; i<rows_*columns_; i++) {
            fileDescriptor_.write(reinterpret_cast<char*>(&zero), sizeof(T));
        }
        fileDescriptor_.close();
    };

    /** @brief konstruktor kopiujący, który powinien utworzyć nowy plik
     *  w tym samym katalogu i o nazwie niemalże identycznej jak `sourceMatrix.filename_`
     *  nazwą pliku ale z suffixem: `_copy` np.:
     *  `path/to/file/matrix100x100.matrix` -> `path/to/file/matrix100x100_copy.matrix`
     *  Zawartość dwóch plików powinna być dokładnie taka sama (zgodność binarna) **/
    FileMatrix(const FileMatrix& sourceMatrix): columns_(sourceMatrix.columns_), rows_(sourceMatrix.rows_) {
        filename_ = sourceMatrix.filename_.substr(0, sourceMatrix.filename_.find('.')) + "_copy" + extention();
        fileDescriptor_.open(filename_, std::ios::out | std::ios::binary);
        std::fstream sourceFile;
        sourceFile.open(sourceMatrix.filename_, std::ios::in | std::ios::binary);
        fileDescriptor_ << sourceFile.rdbuf();
        sourceFile.close();
        fileDescriptor_.close();


    };

    /** @brief konstruktor przenoszący, który zmienić nazwę pliku `sourceMatrix.filename_`
     *  na taki zawierający nazwę z suffixem `_move` w tym samym katalogu
     *  i o nazwie niemalże identycznej np.:
     *  `path/to/file/matrix100x100.matrix` -> `path/to/file/matrix100x100_move.matrix`
     *  `sourceMatrix` powinien być wyczyszczony jak w stanie po zawołaniu
     *  konstruktora przyjmującego jedynie nazwę pliku.
     *  Plik `filename_` nie musi istnieć, ale obiekt
     *  powinien się nadawać do dalszego użytkowania. **/
    FileMatrix(FileMatrix&& sourceMatrix): columns_(sourceMatrix.columns_), rows_(sourceMatrix.rows_) {
        filename_ = sourceMatrix.filename_.substr(0, sourceMatrix.filename_.find('.')) + "_move" + extention();
        fileDescriptor_.open(filename_, std::ios::out | std::ios::binary);
        std::fstream sourceFile;
        sourceFile.open(sourceMatrix.filename_, std::ios::in | std::ios::binary);
        fileDescriptor_ << sourceFile.rdbuf();
        sourceFile.close();
        fileDescriptor_.close();
        std::remove(sourceMatrix.filename_.c_str());
        sourceMatrix.rows_ =0;
        sourceMatrix.columns_=0;
        sourceMatrix.currentRowNumber_ = 0;
        if (sourceMatrix.currentRow_) sourceMatrix.currentRow_.reset();

    };

    /** @brief destruktor - powinien przede wszystkim posprzątać zasoby, które się same nie posprzątają **/
    ~FileMatrix() {
        fileDescriptor_.close();
        currentRow_.reset();

    }

    /** @brief operator przypisania kopiujący, po jego zawołaniu plik
     *  `filename_` powinien mieć zawartość binarnie identyczną do `sourceMatrix.filename_` **/
    FileMatrix& operator=(const FileMatrix& sourceMatrix) {
        if (this==&sourceMatrix) {
            return *this;
        }
        if (fileDescriptor_.is_open()) {
            fileDescriptor_.close();
        }
//        if (std::remove(filename_.c_str())!=0) throw std::runtime_error("Couldn't delete the file in operator=");


        filename_ = sourceMatrix.filename_.substr(0, sourceMatrix.filename_.find('.')) + "_copy" + extention();
        rows_ = sourceMatrix.rows_;
        columns_ = sourceMatrix.columns_;
        currentRowNumber_ = sourceMatrix.currentRowNumber_;


        std::ifstream sourceFile(sourceMatrix.filename_, std::ios::binary);
        if (!sourceFile.is_open()) throw std::runtime_error("Failed to open file.");

        fileDescriptor_.open(filename_, std::ios::binary | std::ios::out);
        if (!fileDescriptor_.is_open()) throw std::runtime_error("Failed to open file.");

        fileDescriptor_ << sourceFile.rdbuf();
        sourceFile.close();
        fileDescriptor_.seekg(2*sizeof(IndexType) + currentRowNumber_*columns_*sizeof(T));
        currentRow_ = std::make_unique<T[]>(columns_);
        fileDescriptor_.read(reinterpret_cast<char*>(currentRow_.get()), columns_*sizeof(T));

        return *this;
    };

    /** @brief operator przypisania przenoszący, po jego zawołaniu plik
     *  `filename_` powinien mieć zawartość dokładnie taką jak `sourceMatrix.filename_`
     *  (najprościej zrobić `rename()` na plikach).
     *  Z kolei plik `filename_` nie musi istnieć, ale obiekt
     *  powinien się nadawać do dalszego użytkowania. **/
    FileMatrix& operator=(FileMatrix&& sourceMatrix){
        filename_ = sourceMatrix.filename_.substr(0, sourceMatrix.filename_.find('.')) + "_move" + extention();
        fileDescriptor_.open(filename_, std::ios::out | std::ios::binary);
        std::fstream sourceFile;
        sourceFile.open(sourceMatrix.filename_, std::ios::in | std::ios::binary);
        fileDescriptor_ << sourceFile.rdbuf();
        sourceFile.close();
        fileDescriptor_.close();
        std::remove(sourceMatrix.filename_.c_str());
        sourceMatrix.rows_ =0;
        sourceMatrix.columns_=0;
        sourceMatrix.currentRowNumber_ = 0;
        if (sourceMatrix.currentRow_) sourceMatrix.currentRow_.reset();

        return *this;
    };

    auto rows() const
	{
        return rows_;
	}

    auto columns() const
	{
        return columns_;
	}

    const auto& filename() const
	{
        return filename_;
	}

    /** @brief operator indeksowania, który zwraca wskaźnik do wskazanego wiersza macierzy.
     *  W razie jeśli w pamięci jest inny należy zrzucić jego dane na dysk i wczytać właściwy wiersz, następnie go zwrócić.
     *  @note Tym sposobem zadziała zawołanie `matrix[row][column]`,
     *        jednakże nie jesteśmy w stanie sprawdzić, czy `column` nie wychodzi poza zakres
     *  **/
    T* operator[](IndexType indexOfRow){
        if (indexOfRow > this->rows_) throw std::out_of_range("index out of range");
        if (currentRow_) this->flush();
        fileDescriptor_.open(filename_, std::ios::in | std::ios::out | std::ios::binary);
        currentRow_.reset(new T[columns_]);
        fileDescriptor_.seekg(2*sizeof(IndexType) + (indexOfRow)*columns_*sizeof(T), std::ios::beg);
        fileDescriptor_.read(reinterpret_cast<char*>(currentRow_.get()), columns_*sizeof(T));
        currentRowNumber_ = indexOfRow;
        fileDescriptor_.close();
        return currentRow_.get();
    };

    /** @brief metoda zrzucająca aktualnie trzymany wiersz w pamięci na dysk.
 *  @note zalecam też aby wołała `fstream::flush()`, aby buforowalne dane zostały mimo wszystko od razu wrzucone na dysk **/
    void flush() {
        T* currentRow = currentRow_.get();
        fileDescriptor_.open(filename_, std::ios::in | std::ios::out | std::ios::binary);
        fileDescriptor_.seekp(2*sizeof(IndexType) + (currentRowNumber_)*columns_*sizeof(T), std::ios::beg);
        fileDescriptor_.write(reinterpret_cast<char*>(currentRow), columns_*sizeof(T));
        fileDescriptor_.flush();
        currentRow_.reset();
        fileDescriptor_.close();
    };

    /** @brief operator indeksowania stały, analogiczny jak operator indeksowania niestały.
     *  @note Aby on działał w analogiczny sposób pewne składowe zapewne będą musiały mieć przedrostem `mutable`. **/
    const T* operator[](IndexType indexOfRow) const {
        if (indexOfRow > this->rows_) throw std::out_of_range("index out of range");
//        if (currentRow_) this->flush();
        fileDescriptor_.open(filename_, std::ios::in | std::ios::out | std::ios::binary);
        currentRow_.reset(new T[columns_]);
        fileDescriptor_.seekg(2*sizeof(IndexType) + (indexOfRow)*columns_*sizeof(T), std::ios::beg);
        fileDescriptor_.read(reinterpret_cast<char*>(currentRow_.get()), columns_*sizeof(T));
        currentRowNumber_ = indexOfRow;
        fileDescriptor_.close();
        return currentRow_.get();
    };

    bool operator==(const FileMatrix& matrix) const {
        if (this==&matrix) return true;
        else if (matrix.rows_!=this->rows_ || matrix.columns_!=this->columns_) return false;

        std::fstream fout, fout2;
        fout.open(filename_, std::ios::in | std::ios::binary);
        fout2.open(matrix.filename_, std::ios::in | std::ios::binary);

        if (fout.tellg() != fout2.tellg()) {
            fout.close();
            fout2.close();
            return false;
        }

        fout.seekg(0);
        fout2.seekg(0);

        char byte1, byte2;
        while (fout.get(byte1) && fout2.get(byte2)) {
            if (byte1 != byte2) {
                fout.close();
                fout2.close();
                return false;
            }
        }

        fout.close();
        fout2.close();

        return true;
    }

	bool operator!=(const FileMatrix& matrix) const
	{
		return !((*this) == matrix);
	}

    /** @brief operator mnożenia całej macierzy przez wartość **/
    FileMatrix& operator*=(const T& value) {
        return *this;

    };

    /** @brief iterator umożliwiający przeglądanie danych idąc wierszami, a następnie w każdym wierszu do każdej kolumny.
     *  Wystarczy, żeby to był iterator jednokierunkowy.
     *  @note Jeśli go zdefiniujesz zdefiniuj makro: `#define FILE_MATRIX_ITERATOR_DEFINED 1` **/
    struct iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        iterator(FileMatrix &matrix, IndexType currentRow, IndexType currentColumn): matrix_(matrix), currentColumn_(currentColumn), currentRow_(currentRow){};
        ~iterator(){
        }
        bool operator==(const iterator& other) const {
            return currentRow_ == other.currentRow_ && currentColumn_ == other.currentColumn_;
        }

        bool operator!=(const iterator& other) const {
            return currentRow_ != other.currentRow_ || currentColumn_ != other.currentColumn_;
        }
        iterator& operator++() {
            if (matrix_.columns_ <= currentColumn_ + 1) {
                currentRow_++;
                currentColumn_ = 0;
            }
            else {
                currentColumn_++;
            }
            return *this;
        }
        const iterator operator++(int) {
            auto tmp = this;
            if (matrix_.columns_ <= currentColumn_ + 1) {
                currentRow_++;
                currentColumn_ = 0;
            }
            else {
                currentColumn_++;
            }
            return *tmp;
        }

        reference operator*() const {
            return matrix_[currentRow_][currentColumn_];
        }
    private:
        FileMatrix<T, IndexType> &matrix_;
        IndexType currentRow_;
        IndexType currentColumn_;

    };

    iterator begin() {
        return iterator(*this, 0, 0);
    };
    iterator end() {
        return iterator(*this, rows_, 0);
    };

private: // methods:
    // TODO: zaimplementuj jesli cos potrzeba

private: // fields:
    std::string filename_;

    IndexType rows_{}, columns_{};

    mutable std::fstream fileDescriptor_;

    mutable std::unique_ptr<T[]> currentRow_;
    mutable IndexType currentRowNumber_{};
};
