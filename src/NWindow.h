/*

This file is from Nitrogen, an X11 background setter.  
Copyright (C) 2006  Dave Foster & Javeed Shaikh

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef _NWINDOW_H_
#define _NWINDOW_H_

#include "main.h"
#include "Thumbview.h"
#include "ImageCombo.h"
#include "SetBG.h"

class NWindow : public Gtk::Window {
	public:
		NWindow ();
		void show (void);
		virtual ~NWindow ();

		Thumbview view;
		void sighandle_dblclick_item(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn * column);
		void sighandle_click_apply(void);
		void sighandle_mode_change(void);

		void set_default_selections();
		
	protected:
		
		Gtk::VBox main_vbox;
		Gtk::HBox bot_hbox, search_hbox;

		ImageCombo select_mode, select_display;

		Gtk::Button apply, dosearch, clearsearch;
		Gtk::CheckButton cb_save;
		Gtk::Expander expand_search;
		Gtk::Entry search_string;
		Gtk::ColorButton button_bgcolor;

		void set_bg(Glib::ustring file);
		void setup_select_boxes();

		bool is_multihead;
};

#endif
