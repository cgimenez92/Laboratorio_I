/*
 * controller.h
 *
 *  Created on: 14 oct. 2020
 *      Author: cgimenez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \adds on list of array, data for control of program
 * in the first empty position
 * \param Publication* listPub
 * \param int lenPub
 * \param Customer* listCus
 * \param int lenCust
 * \param int* flag
 * \return
 */
void controller_force_init(Publication* listPub, int lenPub, Customer* listCust, int lenCust, int* flag);

#endif /* CONTROLLER_H_ */
