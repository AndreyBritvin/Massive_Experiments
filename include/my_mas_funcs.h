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

struct matrix
{
    int *ptr;
    size_t size_x;
    size_t size_y;
};

struct ptr_array
{
    int *ptr;
    size_t size;
};

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
 * @brief Выводит прямоугольную матрицу на экран по структуре
 *
 * @param[in] input_matr Матрица
 *
 * @return int 0 Если успешно
 */
int print_array(struct matrix input_matr);

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
 * @param[in] matr_1 Первая матрица, которую надо перемножить
 * @param[in] matr_2 Вторая матрица, которую надо перемножить
 *
 * @return matrix Матрицу - результата перемножения входных данных
 *
 *
 * @warning Согласно правилам математики необходимо SIZE_Y_1 = SIZE_X_2
 * @warning Коммутативность не допускается!
 */
 struct matrix mult_arrays(struct matrix matr_1,
                           struct matrix matr_2);
/**
 * @brief Находит детерминант (определитель) матрицы рекурсивно через миноры
 *
 * @param[in] input_matrix Входная матрица для которой надо найти определитель
 *
 * @return int Определитель матрицы
 */
int det_array(struct matrix input_matrix);

/**
 * @brief Находит минор матрицы через детерминант (определитель)
 *
 * @param[in] input_matrix Входная матрица для минорирования
 * @param[in] min_i  Индекс строки  элемента, для которого необхоимо найти минор
 * @param[in] min_j  Индекс столбца элемента, для которого необхоимо найти минор
 *
 * @return int Значение минора
 */
int minor_array(struct matrix input_matrix, size_t min_i, size_t min_j);

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
 *
 * @return int* Указатель на начало массива, являющегося обратной матрицей
 *              Её размер такой же, как и размер исходной
 */
struct matrix obr_matrix(struct matrix input_matrix);

/**
 * @brief Ввод прямоугольной матрицы с клаиватуры. Для ввода рваного массива см. input_array()
 *
 * @return int* Указатель на начало матрицы
 */
struct matrix input_matrix();

/**
 * @brief
 *
 * @return int*
 */
struct ptr_array input_array();

/**
 * @brief Get the rows object
 *
 * @param par_name
 * @return size_t
 */
size_t get_rows(const char par_name[]);


#endif // MY_ARR_FUNCS_H__
