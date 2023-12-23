/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#ifndef RS_ACTIONDRAWLINEPOLYGON2_H
#define RS_ACTIONDRAWLINEPOLYGON2_H

#include "rs_previewactioninterface.h"


/**
 * This action class can handle user events to draw polygons.
 *
 * @author Andrew Mustun
 */
class RS_ActionDrawLinePolygonCorCor : public RS_PreviewActionInterface {
	Q_OBJECT
    enum Status {
        SetCorner1,    /**< Setting center 1. */
		SetCorner2,    /**< Setting corner 2. */
		SetNumber      /**< Setting number in the command line. */
	};
	
public:
    RS_ActionDrawLinePolygonCorCor(RS_EntityContainer& container,
                              RS_GraphicView& graphicView);
	~RS_ActionDrawLinePolygonCorCor() override;
	
	void trigger() override;
	
	void mouseMoveEvent(QMouseEvent* e) override;
	void mouseReleaseEvent(QMouseEvent* e) override;
	void updateMouseButtonHints() override;
	
	void coordinateEvent(RS_CoordinateEvent* e) override;
	void commandEvent(RS_CommandEvent* e) override;
		QStringList getAvailableCommands() override;
	
	void hideOptions() override;
	void showOptions() override;

	void updateMouseCursor() override;

	int getNumber() {
		return number;
	}

	void setNumber(int n) {
		number = n;
	}

private:
	struct Points;
	std::unique_ptr<Points> pPoints;
	/** Number of edges. */
    int number = 0;
	/** Last status before entering text. */
    Status lastStatus = SetCorner1;
};

#endif
