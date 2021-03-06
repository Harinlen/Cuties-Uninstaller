/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *  This file is part of Cuties Uninstaller.
 *
 *    Cuties Uninstaller is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or (at your
 *  option) any later version.
 *
 *    Cuties Uninstaller is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along with
 *  Cuties Uninstaller. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QEvent>
#include <QMouseEvent>
#include <QHBoxLayout>
#include "kcgraphicbuttonbase.h"

KCGraphicButtonBase::KCGraphicButtonBase(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *buttonLayout=new QHBoxLayout(this);
    buttonLayout->setContentsMargins(0,0,0,0);
    buttonLayout->setSpacing(0);
    setLayout(buttonLayout);

    buttonGraphic=new QLabel(this);
    buttonGraphic->setContentsMargins(0,0,0,0);
    buttonGraphic->setScaledContents(true);
    buttonLayout->addWidget(buttonGraphic);
}

void KCGraphicButtonBase::visibleDisabled()
{
    setEnabled(false);
    enabled=false;
    buttonGraphic->setVisible(false);
}

void KCGraphicButtonBase::enterEvent(QEvent *e)
{
    if(!enabled)
    {
        e->ignore();
        return;
    }
    buttonGraphic->setPixmap(hoverGraphic);
    QWidget::enterEvent(e);
}

void KCGraphicButtonBase::leaveEvent(QEvent *e)
{
    if(!enabled)
    {
        e->ignore();
        return;
    }
    buttonGraphic->setPixmap(normalGraphic);
    QWidget::leaveEvent(e);
}

void KCGraphicButtonBase::mousePressEvent(QMouseEvent *e)
{
    if(!enabled)
    {
        e->ignore();
        return;
    }
    buttonGraphic->setPixmap(pressedGraphic);
    QWidget::mousePressEvent(e);
    emit pressed();
}

void KCGraphicButtonBase::mouseReleaseEvent(QMouseEvent *e)
{
    if(!enabled)
    {
        e->ignore();
        return;
    }
    buttonGraphic->setPixmap(hoverGraphic);
    QWidget::mouseReleaseEvent(e);
    emit clicked();
}

QPixmap KCGraphicButtonBase::getPressedGraphic() const
{
    return pressedGraphic;
}

void KCGraphicButtonBase::setPressedGraphic(const QPixmap &value)
{
    pressedGraphic = value;
}

QPixmap KCGraphicButtonBase::getHoverGraphic() const
{
    return hoverGraphic;
}

void KCGraphicButtonBase::setHoverGraphic(const QPixmap &value)
{
    hoverGraphic = value;
}

QPixmap KCGraphicButtonBase::getNormalGraphic() const
{
    return normalGraphic;
}

void KCGraphicButtonBase::setNormalGraphic(const QPixmap &value)
{
    normalGraphic = value;
    buttonGraphic->setPixmap(normalGraphic);
}
