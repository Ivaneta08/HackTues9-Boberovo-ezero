# HackTues9-Boberovo-ezero
Създадената програма улеснява съхраняването на пароли и осигурява достъпа до тях само на потребителя. Toй въвежда master парола, която се съхранява във файл "password_safe_key.txt", и я потвърждава. Ако не е потвърдена същата парола, потребителят има определен брой опити (3) да въведе правилната парола и при изчерпването им достъпа до програмата е прекратен. Ако успее да я въведе правилно преди изчерпването на опитите, на потребителя са предоставени четири опции:
  1. Първата опция е Add password, което позволява да се въведе името на сайт, апликацият или др. и съответната му парола. Те се записват в друг файл - "password_safe.txt",където се запазват криптирани. Имената и паролите имат лимит на символите (за пароли - 20, за имена - 30) и броят на паролите също е ограничен (10). Паролите и имената се криптират за допълнителна защита от недоброжелатели.
  2. Втората опция е Show passwords за извеждане на въведените досега пароли от потребителя, изписвайки името на апликацията и съответната парола.
  3. Третата опция е Strong password,която ни дава готова парола от 10 символа.
  4. Четвъртата опция е Exit,която приключва изпълнението на програмата.
  След като сме извършили всички функции ги имаме запазени в криптирания файл и когато въведем master паролата можем да ги видим.

Идеята на програмата е сейф за пароли, въведени от потребителя. При желание на потребителя да ги види, се извеждат всички пароли, съхранени в програмата от създаването на главната парола. Защитени са чрез криптиране. Тази програма е изключително полезна, ако потребителят има много пароли, които не може да запомни.
Направихме проучване с DevOps специалист,който възприема за проблем управляването на паролите за различни сървъри, които са с операционни системи без desktop, а само с терминал. Като tool(инструмент).
