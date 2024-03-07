# Хавронич Евгений Алексеевич, БПИ226
---
## Вариант 18
### Условие:
Разработать программу, которая меняет на обратный порядок следование слов в ASCII–строке символов.То есть,слова остаются написанными правильно. К слову относится последовательность любых символов,неразделяемая пробелами,символами перевода строки,табуляциями.
### Программы:


## Программа была написана на оценку 8.


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
- Даны программа. Пользователь запускает программу. Внутри происходит создание первого именнованного канала, после чего идёт fork, тем самым создавая два родственных процесса. Процесс-родитель читает данные из входного файла, и передаёт данные в первый именованный канал. Процес-ребёнок создаёт второй именованный канал и делает форк, тем самым создавая ещё процесс-ребёнок ребёнка. Процесс ребёнок читает данные из первого канала, обрабатывает их, и передаёт во второй именованный канал, после чего завершает работу. Процесс-ребёнок ребёнка прочитывает всю информацию из второго именнованного канала, и записывает в выходной файлик (или создаёт его).
- Учтены одинаковые требования для баллов ниже (их объяснение смотреть в требованиях на 4 балла).

### Требования на 4:
- Даны программа. Пользователь запускает программу. Внутри происходит создание первого неименнованного канала, после чего идёт fork, тем самым создавая два родственных процесса. Процесс-родитель читает данные из входного файла, и передаёт данные в первый неименованный канал. Процес-ребёнок создаёт второй неименованный канал и делает форк, тем самым создавая ещё процесс-ребёнок ребёнка. Процесс ребёнок читает данные из первого канала, обрабатывает их, и передаёт во второй канал, после чего завершает работу. Процесс-ребёнок ребёнка прочитывает всю информацию из второго канала, и записывает в выходной файлик (или создаёт его).
- Для задания имен входного и выходного файлов используются аргументы командной строки. Учтён некорректный ввод.
- Ввод и вывод данных при работе с файлами осуществляется через системные вызовы операционной системы read и write.
- Размеры буферов для хранения вводимых данных и результатов обработки - 5000 байт.
- Программа работает с тестовыми данными,размер которых не должен превышать размера буфера. То есть, предполагается что весь обрабатываемый текст передается по каналу за один раз.
- Представлен набор(5)текстовых файлов,на которых проводилось тестирование программы(папка readfiles в каждом балле).
- Для каждого из входных тестовых файлов в отчете представлен выходной файл,полученный в результате работы программы (папка writefiles в каждом балле).
- Результаты работы представлены в виде выходных данных.


![](https://i.pinimg.com/564x/2c/34/a7/2c34a7356f7f07f5f867dfe8af1a4758.jpg)
