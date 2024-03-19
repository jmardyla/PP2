Dear Student,

I'm happy to announce that you've managed to get **3.0** out of 3 points for this assignment.

There still exist some issues that should be addressed before the deadline: **2023-06-11 23:50:00 CEST (+0200)**. For further details, please refer to the following list:

<details><summary>Cppcheck znalazł potencjalne błędy (to narzędzie może się pomylić)</summary>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:151:0:&nbsp;warning:&nbsp;The&nbsp;function&nbsp;'reserve'&nbsp;is&nbsp;never&nbsp;used.&nbsp;[unusedFunction]<br>void&nbsp;PtrCStringVector::reserve(size_t&nbsp;new_capacity)<br>^<br></details>
<details><summary>Flawfinder znalazł potencjalne problemy z bezpieczeństwem kodu (to narzędzie może się pomylić)</summary>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:120:14:&nbsp;&nbsp;[4]&nbsp;(buffer)&nbsp;strcpy:Does&nbsp;not&nbsp;check&nbsp;for&nbsp;buffer&nbsp;overflows&nbsp;when&nbsp;copying&nbsp;to&nbsp;destination&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;Consider&nbsp;using&nbsp;snprintf,&nbsp;strcpy_s,&nbsp;or&nbsp;strlcpy&nbsp;(warning:&nbsp;strncpy&nbsp;easily&nbsp;misused).&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strcpy(resultString,&nbsp;(*this)[i]);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:121:14:&nbsp;&nbsp;[4]&nbsp;(buffer)&nbsp;strcat:Does&nbsp;not&nbsp;check&nbsp;for&nbsp;buffer&nbsp;overflows&nbsp;when&nbsp;concatenating&nbsp;to&nbsp;destination&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;Consider&nbsp;using&nbsp;strcat_s,&nbsp;strncat,&nbsp;strlcat,&nbsp;or&nbsp;snprintf&nbsp;(warning:&nbsp;strncat&nbsp;is&nbsp;easily&nbsp;misused).&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strcat(resultString,&nbsp;rhs[i]);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:19:32:&nbsp;&nbsp;[2]&nbsp;(buffer)&nbsp;char:Statically-sized&nbsp;arrays&nbsp;can&nbsp;be&nbsp;improperly&nbsp;restricted,&nbsp;leading&nbsp;to&nbsp;potential&nbsp;overflows&nbsp;or&nbsp;other&nbsp;issues&nbsp;(CWE-119!/CWE-120).&nbsp;&nbsp;Perform&nbsp;bounds&nbsp;checking,&nbsp;use&nbsp;functions&nbsp;that&nbsp;limit&nbsp;length,&nbsp;or&nbsp;ensure&nbsp;that&nbsp;the&nbsp;size&nbsp;is&nbsp;larger&nbsp;than&nbsp;the&nbsp;maximum&nbsp;possible&nbsp;length.&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;**memoryForData&nbsp;=&nbsp;new&nbsp;char&nbsp;*[srcPtrCStringVector.capacity_];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:42:32:&nbsp;&nbsp;[2]&nbsp;(buffer)&nbsp;char:Statically-sized&nbsp;arrays&nbsp;can&nbsp;be&nbsp;improperly&nbsp;restricted,&nbsp;leading&nbsp;to&nbsp;potential&nbsp;overflows&nbsp;or&nbsp;other&nbsp;issues&nbsp;(CWE-119!/CWE-120).&nbsp;&nbsp;Perform&nbsp;bounds&nbsp;checking,&nbsp;use&nbsp;functions&nbsp;that&nbsp;limit&nbsp;length,&nbsp;or&nbsp;ensure&nbsp;that&nbsp;the&nbsp;size&nbsp;is&nbsp;larger&nbsp;than&nbsp;the&nbsp;maximum&nbsp;possible&nbsp;length.&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;**memoryForData&nbsp;=&nbsp;new&nbsp;char&nbsp;*[source.capacity_];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:72:36:&nbsp;&nbsp;[2]&nbsp;(buffer)&nbsp;char:Statically-sized&nbsp;arrays&nbsp;can&nbsp;be&nbsp;improperly&nbsp;restricted,&nbsp;leading&nbsp;to&nbsp;potential&nbsp;overflows&nbsp;or&nbsp;other&nbsp;issues&nbsp;(CWE-119!/CWE-120).&nbsp;&nbsp;Perform&nbsp;bounds&nbsp;checking,&nbsp;use&nbsp;functions&nbsp;that&nbsp;limit&nbsp;length,&nbsp;or&nbsp;ensure&nbsp;that&nbsp;the&nbsp;size&nbsp;is&nbsp;larger&nbsp;than&nbsp;the&nbsp;maximum&nbsp;possible&nbsp;length.&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;**memoryForData&nbsp;=&nbsp;new&nbsp;char&nbsp;*[5&nbsp;*&nbsp;sizeof(char*)];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:77:36:&nbsp;&nbsp;[2]&nbsp;(buffer)&nbsp;char:Statically-sized&nbsp;arrays&nbsp;can&nbsp;be&nbsp;improperly&nbsp;restricted,&nbsp;leading&nbsp;to&nbsp;potential&nbsp;overflows&nbsp;or&nbsp;other&nbsp;issues&nbsp;(CWE-119!/CWE-120).&nbsp;&nbsp;Perform&nbsp;bounds&nbsp;checking,&nbsp;use&nbsp;functions&nbsp;that&nbsp;limit&nbsp;length,&nbsp;or&nbsp;ensure&nbsp;that&nbsp;the&nbsp;size&nbsp;is&nbsp;larger&nbsp;than&nbsp;the&nbsp;maximum&nbsp;possible&nbsp;length.&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;**memoryForData&nbsp;=&nbsp;new&nbsp;char&nbsp;*[2&nbsp;*&nbsp;size_];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:24:42:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;*textInNewVector&nbsp;=&nbsp;new&nbsp;char[strlen(srcPtrCStringVector[i])&nbsp;+&nbsp;1];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:25:14:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strncpy:Easily&nbsp;used&nbsp;incorrectly;&nbsp;doesn't&nbsp;always&nbsp;\0-terminate&nbsp;or&nbsp;check&nbsp;for&nbsp;invalid&nbsp;pointers&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(textInNewVector,&nbsp;srcPtrCStringVector[i],&nbsp;strlen(srcPtrCStringVector[i])&nbsp;+&nbsp;1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:25:63:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(textInNewVector,&nbsp;srcPtrCStringVector[i],&nbsp;strlen(srcPtrCStringVector[i])&nbsp;+&nbsp;1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:47:42:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char&nbsp;*textInNewVector&nbsp;=&nbsp;new&nbsp;char[strlen(source[i])&nbsp;+&nbsp;1];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:48:14:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strncpy:Easily&nbsp;used&nbsp;incorrectly;&nbsp;doesn't&nbsp;always&nbsp;\0-terminate&nbsp;or&nbsp;check&nbsp;for&nbsp;invalid&nbsp;pointers&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(textInNewVector,&nbsp;source[i],&nbsp;strlen(source[i])&nbsp;+&nbsp;1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:48:50:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(textInNewVector,&nbsp;source[i],&nbsp;strlen(source[i])&nbsp;+&nbsp;1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:83:33:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;char*&nbsp;copiedText&nbsp;=&nbsp;new&nbsp;char[strlen(text2Add)+1];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:84:10:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strncpy:Easily&nbsp;used&nbsp;incorrectly;&nbsp;doesn't&nbsp;always&nbsp;\0-terminate&nbsp;or&nbsp;check&nbsp;for&nbsp;invalid&nbsp;pointers&nbsp;[MS-banned]&nbsp;(CWE-120).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(copiedText,&nbsp;text2Add,&nbsp;strlen(text2Add)+1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:84:40:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;std::strncpy(copiedText,&nbsp;text2Add,&nbsp;strlen(text2Add)+1);<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:119:39:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char*&nbsp;resultString&nbsp;=&nbsp;new&nbsp;char[strlen((*this)[i])&nbsp;+&nbsp;strlen(rhs[i])&nbsp;+&nbsp;1];<br>/tmp/tmpmokdg2j6/student/zaj11PtrCStringVector/PtrCStringVector.cpp:119:60:&nbsp;&nbsp;[1]&nbsp;(buffer)&nbsp;strlen:Does&nbsp;not&nbsp;handle&nbsp;strings&nbsp;that&nbsp;are&nbsp;not&nbsp;\0-terminated;&nbsp;if&nbsp;given&nbsp;one&nbsp;it&nbsp;may&nbsp;perform&nbsp;an&nbsp;over-read&nbsp;(it&nbsp;could&nbsp;cause&nbsp;a&nbsp;crash&nbsp;if&nbsp;unprotected)&nbsp;(CWE-126).&nbsp;&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;char*&nbsp;resultString&nbsp;=&nbsp;new&nbsp;char[strlen((*this)[i])&nbsp;+&nbsp;strlen(rhs[i])&nbsp;+&nbsp;1];<br></details>

-----------
I remain your faithful servant\
_Bobot_