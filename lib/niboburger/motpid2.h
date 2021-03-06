/*  BSD-License:

Copyright (c) 2007 by Nils Springob, nicai-systems, Germany

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the name nicai-systems nor the names of its contributors may be
    used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/*! @file    motpid.h
 *  @brief   PID-Regler
 *
 *  Weitere Informationen: <a href="http://www.nibo-roboter.de/wiki/NIBObee/Motorregelung">Motorregelung im NIBObee-Wiki</a>
 *  @author  Nils Springob (springob@nicai-systems.com)
 *  @date    2015-06-06
 */

#ifndef _NIBOBURGER_MOTPID_H_
#define _NIBOBURGER_MOTPID_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * Initialiserung für PID Regler.
 */
void motpid_init();


/*!
 * Der PID Regler gibt die Kontrolle über das PWM Signal wieder frei. Die
 * PWM-Werte werden nicht verändert!
 */
void motpid_release();


/*!
 * Soll-Geschwindigkeit auf 0 setzen.
 * Der Parameter @param immediate bestimmt wie der Roboter anhält: Der Wert 0
 * bedeutet sanftes anhalten, andere Werte abruptes anhalten.
 */
void motpid_stop(uint8_t immediate);


/*!
 * Soll-Geschwindigkeit für die Motoren setzen.
 * @param left sollte im Interval [-100 ... +100] liegen und wird in
 * Ticks/Sekunde angegeben.
 * @param right sollte im Interval [-100 ... +100] liegen und wird in
 * Ticks/Sekunde angegeben.
 */
void motpid_setSpeed(int16_t left, int16_t right);


/*!
 * Absolute Ziel-Position setzen.
 * @param left Position für linkes Rad
 * @param right Position für rechtes Rad
 * @param speed sollte im Interval [-100 ... +100] liegen und wird in
 * Ticks/Sekunde angegeben.
 */
void motpid_setTarget(int16_t left, int16_t right, uint16_t speed);


/*!
 * Relative Ziel-Position setzen.
 * @param left Position für linkes Rad
 * @param right Position für rechtes Rad
 * @param speed sollte im Interval [-100 ... +100] liegen und wird in
 * Ticks/Sekunde angegeben.
 */
void motpid_setTargetRel(int16_t left, int16_t right, uint16_t speed);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _NIBOBURGER_MOTPID_H_
