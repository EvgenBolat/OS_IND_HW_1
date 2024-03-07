# Хавронич Евгений Алексеевич, БПИ226
---
## Вариант 18
### Условие:
Разработать программу, определяющую корень уравнения x<sup>4</sup>−x<sup>3</sup>−2.5 = 0 **методом хорд** с точностью от 0,001 до 0,00000001 в диапазоне [1;2]. Если диапазон некорректен, то подобрать корректный диапазон.
### Программы:
[Программы на ассемблере с комментариями размещены здесь](Files/RISKFILES)

Требование перед запуском программ: Должны быть поставлены следующие настройки во вкладке settings, так как используются глобальные метки:

![](Files/Settings.png)
## Программа была написана на оценку 10.


### Требования на 8:
- Даны две программы, которые олицетворяю два независимых процесса. Пользователь запускает обе программы. Процесс в первом файле читает данные из входного файла, и передаёт данные в первый именованный канал, после чего ждёт во втором канале получения информации(так как там пусто, то он блокируется до попадания в канал какой-либо информации). Процесс во втором файле читает данные из первого канала, обрабатывает их, и передаёт во второй канал, после чего завершает работу. Первый процесс получает снятие блокировки со второго канала, поэтому он прочитывает всю информацию оттуда, и записывает в выходной файлик (или создаёт его).
- Учтены одинаковые требования для баллов ниже (их объяснение смотреть в требованиях на 4 балла).

### Требования на 7:
- Даны программа. Пользователь запускает программу. Внутри происходит fork, тем самым создавая два родственных процесса. Процесс-родитель читает данные из входного файла, и передаёт данные в первый именованный канал, после чего ждёт во втором канале получения информации(так как там пусто, то он блокируется до попадания в канал какой-либо информации). Процес-ребёнок читает данные из первого канала, обрабатывает их, и передаёт во второй канал, после чего завершает работу. Процесс-ребёнок получает снятие блокировки со второго канала, поэтому он прочитывает всю информацию оттуда, и записывает в выходной файлик (или создаёт его).
- Учтены одинаковые требования для баллов ниже (их объяснение смотреть в требованиях на 4 балла).

### Требования на 6:
- Даны программа. Пользователь запускает программу. Внутри происходит fork, тем самым создавая два родственных процесса. Процесс-родитель читает данные из входного файла, и передаёт данные в первый неименованный канал, после чего ждёт во втором канале получения информации(так как там пусто, то он блокируется до попадания в канал какой-либо информации). Процес-ребёнок читает данные из первого канала, обрабатывает их, и передаёт во второй неименованный канал, после чего завершает работу. Процесс-ребёнок получает снятие блокировки со второго канала, поэтому он прочитывает всю информацию оттуда, и записывает в выходной файлик (или создаёт его).
- Учтены одинаковые требования для баллов ниже (их объяснение смотреть в требованиях на 4 балла).

### Требования на 5:
- Даны программа. Пользователь запускает программу. Внутри происходит создание первого неименнованного канала, после чего идёт fork, тем самым создавая два родственных процесса. Процесс-родитель читает данные из входного файла, и передаёт данные в первый неименованный канал, после чего ждёт во втором канале получения информации(так как там пусто, то он блокируется до попадания в канал какой-либо информации). Процес-ребёнок читает данные из первого канала, обрабатывает их, и передаёт во второй неименованный канал, после чего завершает работу. Процесс-ребёнок получает снятие блокировки со второго канала, поэтому он прочитывает всю информацию оттуда, и записывает в выходной файлик (или создаёт его).
- Учтены одинаковые требования для баллов ниже (их объяснение смотреть в требованиях на 4 балла).

## Общий алгоритм программы.
1. Вызов макроса **read_double**. В качестве аргумента получаем регистр, куда будет передано double число. В этом макросе происходит вызов ввода double числа.
2. Вызов подпрограммы **FindX**. В неё передаётся double число в качестве параметрав в fa0, который мы получили ранее. Если число попадает в нужный нам диапозон, то по завершению работы, подпрограмма вернёт в fa0 корень уравнения, если число не попадает в нужный нам диапозон, то подпрограмма выводит строчку о непопадании в диапозон и делает вызов завершения программы.
    1. Вызов **IsCorrectInterv**. Аргументы аналогичны тем, что передавались в FindX. Если число попадает в отрезок 0,001 до 0,00000001, то макрос успешно завершает свою работу и выполнение программы продолжается дальше. Если не попадает, то программа завершается и выводится сообщение о причине завершения программы.
    2. Вызов **RetX**. Первый аргумент аналогичен передававшимся в последних двух описанных функциях, также передаётся регистр, в котором размещена левая граница искомого корня;регистр, в котором размещена правая граница искомого корня, и регистр, куда должен быть передан корень уравнения. Так как границы у нас предопределены и не изменяются (1 и 2), то проверку на корректность границ мы не делаем.
3. Вызов **ArrayFromElemLessSum**. Аргументы: сумма элементов на чётных индексах массива А, размер массива А, указатель на массив А, указатель на массив B, регистр, куда запишется размер заполненного массива B. В данном макросе происходит запись элементов массива А в массив B, которые меньше переданной в качестве первого аргумента суммы. Из макроса в последний параметр записывается размер заполненного массива.
7. вызов newline, print_str и print_double – эти макросы формируют вывод нашего корня.

### Описание метода решения задачи (нахождения корня уравнения методом хорд)

Пусть x<sub>1</sub>,x<sub>2</sub> — абсциссы концов хорды, f(x)=0 — уравнение функции, решаемое методом секущих. Найдём коэффициенты k и b из системы уравнений

![](Files/descr/1.png)

Вычтем из первого уравнения второе:

![](Files/descr/2.png)

затем найдём коэффициенты k и b:

![](Files/descr/3.png)

тогда

![](Files/descr/4.png)

Уравнение принимает вид

![](Files/descr/5.png)

Таким образом, теперь можем найти первое приближение к корню, полученное методом секущих:

![](Files/descr/6.png)

Теперь возьмём координаты x<sub>2</sub> и x<sub>3</sub> и повторим все проделанные операции, найдя новое приближение к корню. Таким образом, итерационная формула метода секущих имеет вид:

![](Files/descr/7.png)

Данную формулу мы и будем использовать для итерационного алгоритма нахождения корня:
x<sub>i</sub>-ым будет являться a; x<sub>i + 1</sub>-ым будет являться b.
Как только разница между a и b становится меньше нужной нам точности, то возвращаем b – то есть x<sub>i + 1</sub>.
### Таблица прогона полного тестового покрытия

<table>
    <tr>
        <th>№ теста</th>
        <th>Какую ситуацию проверяет</th>
        <th>Введённая точность</th>
        <th>Полученный X </th>
    </tr>
    <tr>
        <td>1</td>
        <td>Точность равна правой границе диапозона</td>
        <td>0.001</td>
        <td>1.6048396218292138</td>
    </tr>
    <tr>
        <td>2</td>
        <td>Точность чуть меньше правой границы диапозона</td>
        <td>0.0009</td>
        <td>1.6048396218292138</td>
    </tr>
    <tr>
        <td>3</td>
        <td>Произвольная точность из нужного диапозона</td>
        <td>0.000005</td>
        <td>1.6048428005867157</td>
    </tr>
    <tr>
        <td>4</td>
        <td>Точонсть чуть больше левой границы диапозона</td>
        <td>0.00000002</td>
        <td>1.6048428005867157</td>
    </tr>
    <tr>
        <td>5</td>
        <td>Точность равна правой границе диапозона</td>
        <td>0.00000001</td>
        <td>1.6048427993525602</td>
    </tr>
    <tr>
        <td>6</td>
        <td>Точность меньше правой границы диапозона</td>
        <td>0.000000009</td>
        <td>Accuracy should be in the range of 0.001 to 0.00000001</td>
    </tr>
    <tr>
        <td>7</td>
        <td>Точность больше левой границы диапозона</td>
        <td>0.002</td>
        <td>Accuracy should be in the range from 0.001 to 0.00000001</td>
    </tr>
</table>


![](https://i.pinimg.com/564x/2c/34/a7/2c34a7356f7f07f5f867dfe8af1a4758.jpg)
