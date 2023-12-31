# 1. Цель лабораторной работы
Исследование эффекта от использования классов.
# 2. Задание для лабораторной работы
Разработать программу, которая выполняет вычисление конечного множества Е, содержащее все цифры, общие для A и B, а также все цифры, являющиеся общими для C и D. Универсум: шестнадцатеричные цифры.
Использовать объектно-ориентированный подход.
# 3. Выводы
Основываясь на данных, полученных в пункте 3, что самым быстрым способом работы с множествами является способ представления в массиве битов. Для большей оптимизации предлагается размещать данные из массивов битов в регистры AX, BX, CX и DX и пользоваться инструкциями AND и OR.

Машинные слова также хороший способ работы со множествами, поскольку поразрядные операции выполняются намного быстрее, чем операции сложения, которые есть в других вариантах реализаций, а код метода работы с машинными словами занимает намного меньше места.

Метод размещения множеств в списках показал худшее время обработки. Это связано с тем, что в стандартной реализации list в С++ не определена операция обращения к элементу по индексу или функция at(), что вынуждает использовать функции удаления элементов списка в ходе выполнения вычислений. Это значительно замедляет работу алгоритма.

Объектно-ориентированный подход, по сравнению с процедурным, реализованным в предыдущей работе, показал примерно такое же время работы алгоритмов, в зависимости от мощности множеств, но при этом, требовал больше выделенной памяти под временные переменные и исходные данные, что в свою очередь, при масштабировании проекта, может привести к неприятнымпоследствиям.

# 4. Списоки использованных источников
1) Колинько П.Г. Алгоритмы и структуры данных. Часть1: Пособие к самостоятельной работе и курсовому проектированию. Вып. 2001 (для заочников).–СПб.,2020.– 71 с.
2) Быстрая сортировка: http://cppstudio.com/post/891/?ysclid=lj8e3kdw6z
