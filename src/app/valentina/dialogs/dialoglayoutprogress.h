/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017  Seamly, LLC                                       *
 *                                                                         *
 *   https://github.com/valentina-project/vpo2                             *
 *                                                                         *
 ***************************************************************************
 **
 **  Seamly2D is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Seamly2D is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Seamly2D.  If not, see <http://www.gnu.org/licenses/>.
 **
 **************************************************************************

 ************************************************************************
 **
 **  @file   dialoglayoutprogress.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   14 1, 2015
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://github.com/valentina-project/vpo2> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef DIALOGLAYOUTPROGRESS_H
#define DIALOGLAYOUTPROGRESS_H

#include <QDialog>

#include "../vlayout/vlayoutdef.h"

namespace Ui
{
    class DialogLayoutProgress;
}

class DialogLayoutProgress : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLayoutProgress(int count, QWidget *parent = nullptr);
    ~DialogLayoutProgress();

signals:
    void Abort();

public slots:
    void Start();
    void Arranged(int count);
    void Error(const LayoutErrors &state);
    void Finished();

protected:
    virtual void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(DialogLayoutProgress)
    Ui::DialogLayoutProgress *ui;
    const int maxCount;
    QMovie *movie;
    bool isInitialized;
};

#endif // DIALOGLAYOUTPROGRESS_H
