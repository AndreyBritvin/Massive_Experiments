/**
 * @file my_mas_funcs.h
 * @author Andrey Britvin
 * @brief Различные операции с матрицами:
 *        Печать матрицы, сложение двух матрицей, перемножение матриц, нахождение определителя,
 *        нахождение минора элемента и применение к нему алгебраического дополнения
 *
 * @version 1.0
 * @date 2024-08-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MY_ARR_FUNCS_H__
#define MY_ARR_FUNCS_H__

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

/**
 * @brief Выводит прямоугольную матрицу на экран
 *
 * @param[in] data Матрица, которую надо вывести на экран
 * @param[in] x    Горизонтальный размер массива; Количество рядов
 * @param[in] y    Вертикальный размер массива;   Длина ряда
 *
 * @return int 0 Если успешно
 */
int print_array(int *data, size_t x, size_t y);

/**
 * @brief Выводит треугольный массив на экран ("турнирную сетку")
 *
 * @param[in] data  Массив, который надо вывести
 * @param[in] total Общее кол-во элементов на вывод
 *
 * @return int 0 Если всё успешно
 */
int print_tr_array(int *data, size_t total);

/**
 * @brief Суммирует две матрицы и возвращает третью матрицу - сумму двух предыдущих.
 *
 * @param[in] size_x Количество рядов в матрице
 * @param[in] size_y Количество столбцов в матрице
 * @param[in] data_1 Первая матрица для сложения
 * @param[in] data_2 Вторая матрица для сложения
 *
 * @return int* Указатель на начало массива - результата сложеня двух матриц
 *
 * TODO: складывать в первую матрицу
 */
int *sum_arrays(size_t size_x, size_t size_y, int *data_1, int *data_2);

/**
 * @brief Перемножение двух матриц
 *
 * @param[in] data_1   Первая матрица, которую надо перемножить
 * @param[in] SIZE_X_1 Количество рядов    в первой матрице
 * @param[in] SIZE_Y_1 Количество столбцов в первой матрице
 * @param[in] data_2   Вторая матрица, которую надо перемножить
 * @param[in] SIZE_X_2 Количество рядов    в второй матрице
 * @param[in] SIZE_X_1 Количество столбцов в второй матрице
 *
 * @return int* Указатель на начало матрицы - результата перемножения входных данных
 *              Размер матрицы не возвращается, но он будет SIZE_X_1 * SIZE_Y_2
 *
 * @warning Согласно правилам математики необходимо SIZE_Y_1 = SIZE_X_2
 * @warning Коммутативность не допускается!
 */
int *mult_arrays(int *data_1, size_t SIZE_X_1, size_t SIZE_Y_1,
                 int *data_2, size_t SIZE_X_2, size_t SIZE_Y_2);

/**
 * @brief Находит детерминант (определитель) матрицы рекурсивно через миноры
 *
 * @param[in] matr   Матрица, для которой необходимо найти определитель
 * @param[in] SIZE   Размер матрицы (по-хорошему, квадратной)
 * @param[in] SIZE_Y Количество стобцов, по-моему не используется
 *
 * @return int Определитель матрицы
 */
int det_array(int *matr, size_t SIZE, size_t SIZE_Y);

/**
 * @brief Находит минор матрицы через детерминант (определитель)
 *
 * @param[in] matr   Матрица, для которой необходимо найти минор
 * @param[in] SIZE   Размер матрицы
 * @param[in] SIZE_Y Количество стобцов, по-моему не используется, но для будущего пусть будет
 * @param[in] min_i  Индекс строки  элемента, для которого необхоимо найти минор
 * @param[in] min_j  Индекс столбца элемента, для которого необхоимо найти минор
 *
 * @return int Значение минора
 */
int minor_array(int *matr, size_t SIZE, size_t SIZE_Y, size_t min_i, size_t min_j);

/**
 * @brief Алгебраическое дополнение для элемента
 *
 * @param[in] dop_i Индекс строки  элемента
 * @param[in] dop_j Индекс столбца элемента
 * @param[in] minor Минор          элемента
 *
 * @return int Алгебраическое дополнение
 */
int alg_dop(size_t dop_i, size_t dop_j, int minor);

/**
 * @brief Находит обратную матрицу через определитель и миноры (и алгебраическую подстановку
 *        с учётом транспонирования внутри функции); TODO: Вынести транспонирование в отдельную функцию
 *
 * @param[in] matr   Матрица, для которой необходимо найти обратную
 * @param[in] SIZE   Размер матрицы
 * @param[in] SIZE_Y Количество стобцов, по-моему не используется
 *
 * @return int* Указатель на начало массива, являющегося обратной матрицей
 *              Её размер такой же, как и размер исходной
 */
int *obr_matrix(int *matr, size_t SIZE, size_t SIZE_Y);

#endif // MY_ARR_FUNCS_H__
