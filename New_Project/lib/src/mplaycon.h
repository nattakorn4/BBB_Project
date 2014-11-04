/*
 *  Written By: Grant Hutchinson
 *  License: GPLv3.
 *  h.g.utchinson@gmail.com
 *  Copyright (C) 2012 by Grant Hutchinson
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MPLAYCON_H
#define MPLAYCON_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QtCore>
#include <QtGui>
#include "qmpwidget.h"
#include "preferences.h"
#include "playlistobj.h"
class mplayCon : public QThread
{
 //   Q_OBJECT
public:
    mplayCon(QObject *parent);


    QMPwidget widget2;
    playlistobj pl;
    preferences pref;
    int pl_selected;

    mplayCon();
    void startSong(char *FinSong, int selID);

    virtual ~mplayCon();

    void run();

private:
    void set(playlistobj &plobj, preferences prefs, int plselected);

};

#endif // MPLAYCON_H
