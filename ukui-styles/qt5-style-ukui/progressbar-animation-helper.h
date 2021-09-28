/*
 * Qt5-UKUI's Library
 *
 * Copyright (C) 2020, Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Authors: Yue Lan <lanyue@kylinos.cn>
 *
 */

#ifndef PROGRESSBARANIMATIONHELPER_H
#define PROGRESSBARANIMATIONHELPER_H

#include <QObject>
#include <QVariantAnimation>
#include <QHash>
#include "progressbar-animation.h"


class ProgressBarAnimationHelper : public QObject
{
    Q_OBJECT
public:
    ProgressBarAnimationHelper(QObject *parent = nullptr);
    virtual ~ProgressBarAnimationHelper();

    void startAnimation(QVariantAnimation *animation);
    void stopAnimation(QObject *target);
    QVariantAnimation* animation(QObject *target);

public slots:
    void _q_removeAnimation();

private:
    QHash<QObject*, QVariantAnimation*> *animations;
};

#endif // PROGRESSBARANIMATIONHELPER_H
