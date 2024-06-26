# paradigms_caesar
 
**1. What is a low-level language?**
   little or no abstraction from a computer's instruction set architecture
   іноді описують як «близькі до апаратного забезпечення», а не до програмного забезпечення
   - Мова низького рівня має високу ефективність пам'яті.
   - _Машинна мова_ (це мова низького рівня, яка складається з двійкових кодів, якими безпосередньо керує центральний процесор ЦП)
   - _Мова асемблера_ (це спосіб написання комп'ютерних програм, який дуже близький до роботи комп'ютера. Він містить деякі символи та коди, які представляють основні операції, які може виконувати комп’ютер, зокрема додавання, переміщення чи порівняння чисел.)

Вони забезпечують _невелику абстракцію_ від машинних інструкцій або зовсім не абстрагуються , і тому вони дозволяють програмістам маніпулювати апаратними елементами, такими як регістр, пам’ять тощо. Мови низького рівня часто використовуються для проектування систем, таких як розробка операційних систем , драйверів пристроїв і вбудованих систем .
   
**2. Key characteristics of procedural, structured and imperative languages.**
<img width="748" alt="Знімок екрана 2024-06-25 о 23 28 32" src="https://github.com/YelyzavetaZahorulko/paradigms_caesar/assets/151025903/95049481-55e4-4d7e-b68d-b18076b37b18">


<img width="773" alt="Знімок екрана 2024-06-25 о 23 29 23" src="https://github.com/YelyzavetaZahorulko/paradigms_caesar/assets/151025903/2e2493b1-f0c1-43dd-b66b-ff90da9a6a63">

**3. What is a dynamic library?**
   Динамічні бібліотеки надають код, який можна завантажити будь-де в пам'ять. Після завантаження код бібліотеки може використовуватися будь-якою кількістю програм. Таким чином розмір програм, які використовують динамічну бібліотеку, і обсяг пам’яті можуть бути максимально низькими
   - У виконуваному файлі є посилання лише на адресу бібліотеки.
   - Менші виконувані файли.
   - Мають префікс lib і розширення .so
     
**4. What is a static library?**
   - Скопіюйте безпосередньо у свій виконуваний файл.
   - Мають префікс lib і розширення .a.
   - Виконуваний файл не оновлюється автоматично, коли є зміни в бібліотеці.

     
**5. What is a compiler?**
   Компілятор - це програма, яка перетворює вихідний код у машинний код. Потім ця програма використовується для створення машинного коду, який можна використовувати для запуску програми.
   
**6. What is a linker?**
   це програма в системі, яка допомагає зв’язувати об’єктні модулі програми в один об’єктний файл. Він виконує процес зв'язування
   
**7. Why do we need `extern "C"` construct in the code?**
Рядок extern "C" повідомляє компілятору, що зовнішня інформація, надіслана до компонувальника, повинна використовувати угоди про виклики C та спотворення імен
Коли нам потрібно зв'язати код на C++ з бібліотеками, написаними на C.

**8. What is a function pointer?**
    На відміну від звичайних покажчиків, покажчик функції вказує на код, а не на дані. Зазвичай покажчик функції зберігає початок виконуваного коду.
   Звільнення вказівника на функцію повертає функцію, на яку є посилання, яку можна викликати і передавати аргументи так само, як і при звичайному виклику функції.
