/*
 * calculator_operations.h
 *
 *  Created on: 8 sep. 2020
 *      Author: cgimenez
 */

#ifndef CALCULATOR_OPERATIONS_H_
#define CALCULATOR_OPERATIONS_H_

/**
 * \brief Solicita al usuario dos valores flotantes y regresa en un puntero el resultado de su suma.
 * \param float firstOperator Primer valor a sumar
 * \param float secondOperator Segundo valor a sumar
 * \param float* pResult puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) Puntero pResult no es nulo (Ok)/ (-1) Puntero pResult es nulo (Error)
 */
int fSumOperation(float firstOperator, float secondOperator, float* pResult);

/**
 * \brief Solicita al usuario dos valores flotantes y regresa en un puntero el resultado de su resta.
 * \param float firstOperator Primer valor a restar
 * \param float secondOperator Segundo valor a restar
 * \param float* pResult puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) Puntero pResult no es nulo (Ok)/ (-1) Puntero pResult es nulo (Error)
 */
int fRestOperation(float firstOperator, float secondOperator, float* pResult);

/**
 * \brief Solicita al usuario dos valores flotantes y regresa en un puntero el resultado de su division.
 * \param float firstOperator Primer valor a dividir
 * \param float secondOperator Segundo valor a dividir
 * \param float* pResult puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) Puntero pResult no es nulo (Ok)/ (-1) Puntero pResult es nulo (Error)
 */
int fDivideOperation(float firstOperator, float secondOperator, float* pResult);


/**
 * \brief Solicita al usuario dos valores flotantes y regresa en un puntero el resultado de su multiplicacion.
 * \param float firstOperator Primer valor a multiplicar
 * \param float secondOperator Segundo valor a multiplicar
 * \param float* pResult puntero al espacio de memoria donde se dejara el valor obtenido.
 * \return (0) Puntero pResult no es nulo (Ok)/ (-1) Puntero pResult es nulo (Error)
 */
int fMultiplyOperation(float firstOperator, float secondOperator, float* pResult);


/**
 * \brief Solicita al usuario dos valores flotantes y regresa en un puntero el resultado de su suma.
 * \param float firstOperator Primer valor a sumar
 * \param float secondOperator Segundo valor a sumar
 * \param float* pResultFirstOperator puntero al espacio de memoria donde se dejara el valor obtenido del factorial del primer valor
 * \param float* pResultSecondOperator puntero al espacio de memoria donde se dejara el valor obtenido del factorial del segundo valor
 * \return (0) Puntero pResult no es nulo (Ok)/ (-1) Puntero pResult es nulo (Error) / (-2) firstOperator menor a 0 (Error) / (-3) secondOperator menor a 0 (Error)
 */
int fFactorial(float firstOperator, float secondOperator, unsigned long int* pResultFirstOperator, unsigned long int* pResultSecondOperator);

#endif /* CALCULATOR_OPERATIONS_H_ */
