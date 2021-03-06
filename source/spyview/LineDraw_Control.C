// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include "LineDraw_Control.h"
#include "ImageWindow.H"
#include "ImageWindow_LineDraw.H"
#include <FL/Fl_File_Chooser.H>

void LineDraw_Control::cb_dismiss_i(Fl_Button*, void*) {
  win->hide();
}
void LineDraw_Control::cb_dismiss(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_dismiss_i(o,v);
}

void LineDraw_Control::cb_Reload_i(Fl_Button*, void*) {
  LineDrawer->loadGnuplotLines(file->value());
}
void LineDraw_Control::cb_Reload(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->parent()->user_data()))->cb_Reload_i(o,v);
}

void LineDraw_Control::cb_autognu_i(Fl_Light_Button*, void*) {
  if(autognu->value())
  LineDrawer->watchGnuplot();
}
void LineDraw_Control::cb_autognu(Fl_Light_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->parent()->user_data()))->cb_autognu_i(o,v);
}

void LineDraw_Control::cb_endpoints_i(Fl_Check_Button*, void*) {
  LineDrawer->iw->redraw_overlay();
}
void LineDraw_Control::cb_endpoints(Fl_Check_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_endpoints_i(o,v);
}

void LineDraw_Control::cb_highlight_nl_i(Fl_Light_Button*, void*) {
  LineDrawer->iw->redraw_overlay();
}
void LineDraw_Control::cb_highlight_nl(Fl_Light_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_highlight_nl_i(o,v);
}

void LineDraw_Control::cb_Info_i(Fl_Button*, void*) {
  if (nl_info_win->shown())
	nl_info_win->hide();
else
{
	nl_info_win->show();
	LineDrawer->update_info_win();
};
}
void LineDraw_Control::cb_Info(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Info_i(o,v);
}

void LineDraw_Control::cb_Delete_i(Fl_Button*, void*) {
  while(!LineDrawer->lines.empty())
	LineDrawer->lines.pop_front();
LineDrawer->iw->redraw_overlay();
}
void LineDraw_Control::cb_Delete(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Delete_i(o,v);
}

void LineDraw_Control::cb_Load_i(Fl_Button*, void*) {
  string name=LineDrawer->iw->output_basename;
name += ".lines";
LineDrawer->loadLines(name.c_str());
}
void LineDraw_Control::cb_Load(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

void LineDraw_Control::cb_Save_i(Fl_Button*, void*) {
  string name=LineDrawer->iw->output_basename;
name += ".lines";
LineDrawer->saveLines(name.c_str());
}
void LineDraw_Control::cb_Save(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

void LineDraw_Control::cb_Load1_i(Fl_Button*, void*) {
  Fl_File_Chooser chooser(".", 
			"(*.lines)\t",
			Fl_File_Chooser::SINGLE,
			"Select files");
chooser.preview(0);
chooser.show();
while (chooser.shown()) Fl::wait();
if (chooser.value() == NULL) return;
LineDrawer->loadLines(chooser.value(1));
}
void LineDraw_Control::cb_Load1(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Load1_i(o,v);
}

void LineDraw_Control::cb_Save1_i(Fl_Button*, void*) {
  Fl_File_Chooser chooser(".", 
			"(*.lines)\t",
			Fl_File_Chooser::CREATE,
			"Select files");
chooser.preview(0);
chooser.show();
while (chooser.shown()) Fl::wait();
if (chooser.value() == NULL) return;
LineDrawer->saveLines(chooser.value(1));
}
void LineDraw_Control::cb_Save1(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_Save1_i(o,v);
}

void LineDraw_Control::cb_plot_nl_i(Fl_Light_Button*, void*) {
  LineDrawer->iw->redraw_overlay();
}
void LineDraw_Control::cb_plot_nl(Fl_Light_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_plot_nl_i(o,v);
}

void LineDraw_Control::cb_line_display_i(Fl_Browser*, void*) {
  //LineDrawer->nearest = line_display->selection()->user_data();
}
void LineDraw_Control::cb_line_display(Fl_Browser* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_line_display_i(o,v);
}

void LineDraw_Control::cb_dismiss1_i(Fl_Button*, void*) {
  nl_info_win->hide();
}
void LineDraw_Control::cb_dismiss1(Fl_Button* o, void* v) {
  ((LineDraw_Control*)(o->parent()->user_data()))->cb_dismiss1_i(o,v);
}

LineDraw_Control::LineDraw_Control() {
  { win = new Fl_Double_Window(300, 240, "Line Draw");
    win->user_data((void*)(this));
    { Fl_Button* o = new Fl_Button(5, 215, 290, 20, "dismiss");
      o->labelsize(11);
      o->callback((Fl_Callback*)cb_dismiss);
    } // Fl_Button* o
    { Fl_Group* o = new Fl_Group(0, 15, 300, 65, "Gnuplot Overlay");
      o->box(FL_DOWN_BOX);
      o->labelsize(11);
      o->align(FL_ALIGN_TOP_LEFT);
      { Fl_Button* o = new Fl_Button(190, 28, 100, 22, "&Reload");
        o->labelsize(11);
        o->callback((Fl_Callback*)cb_Reload);
      } // Fl_Button* o
      { Fl_File_Input* o = file = new Fl_File_Input(35, 19, 145, 31, "File");
        file->labelsize(11);
        file->textsize(11);
        o->value("/tmp/table.dat");
      } // Fl_File_Input* file
      { autodelete = new Fl_Light_Button(190, 55, 100, 20, "&Autodelete");
        autodelete->value(1);
        autodelete->labelsize(11);
      } // Fl_Light_Button* autodelete
      { autognu = new Fl_Light_Button(85, 55, 100, 20, "&Autoload");
        autognu->labelsize(11);
        autognu->callback((Fl_Callback*)cb_autognu);
      } // Fl_Light_Button* autognu
      o->end();
    } // Fl_Group* o
    { endpoints = new Fl_Check_Button(5, 85, 100, 20, "Draw Endpoints");
      endpoints->down_box(FL_DOWN_BOX);
      endpoints->callback((Fl_Callback*)cb_endpoints);
    } // Fl_Check_Button* endpoints
    { highlight_nl = new Fl_Light_Button(155, 115, 140, 20, "Highlight NL");
      highlight_nl->callback((Fl_Callback*)cb_highlight_nl);
    } // Fl_Light_Button* highlight_nl
    { Fl_Button* o = new Fl_Button(155, 140, 140, 20, "Info Window");
      o->callback((Fl_Callback*)cb_Info);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(5, 140, 140, 20, "Delete all");
      o->tooltip("Shft-D");
      o->callback((Fl_Callback*)cb_Delete);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(5, 165, 140, 20, "Load Default");
      o->tooltip("Load lines from file \"filename.lines\"");
      o->callback((Fl_Callback*)cb_Load);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(5, 190, 140, 20, "Save Default");
      o->tooltip("Save lines to file \"filename.lines\"");
      o->callback((Fl_Callback*)cb_Save);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 165, 140, 20, "Load...");
      o->tooltip("Load lines from a file");
      o->callback((Fl_Callback*)cb_Load1);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(155, 190, 140, 20, "Save...");
      o->tooltip("Save lines to a file");
      o->callback((Fl_Callback*)cb_Save1);
    } // Fl_Button* o
    { plot_nl = new Fl_Light_Button(5, 115, 140, 20, "Plot NL");
      plot_nl->callback((Fl_Callback*)cb_plot_nl);
      plot_nl->deactivate();
    } // Fl_Light_Button* plot_nl
    win->end();
  } // Fl_Double_Window* win
  { nl_info_win = new Fl_Double_Window(315, 355, "Line Info");
    nl_info_win->user_data((void*)(this));
    { Fl_Group* o = new Fl_Group(10, 10, 280, 15);
      { Fl_Round_Button* o = new Fl_Round_Button(10, 10, 70, 15, "Real units");
        o->type(102);
        o->down_box(FL_ROUND_DOWN_BOX);
        o->value(1);
      } // Fl_Round_Button* o
      { nl_pixels = new Fl_Round_Button(105, 10, 70, 15, "PIxels");
        nl_pixels->type(102);
        nl_pixels->down_box(FL_ROUND_DOWN_BOX);
      } // Fl_Round_Button* nl_pixels
      o->end();
    } // Fl_Group* o
    { Fl_Input* o = nl_fmt = new Fl_Input(210, 8, 50, 20, "fmt:");
      o->value("%.3g");
    } // Fl_Input* nl_fmt
    { nl_x1 = new Fl_Output(25, 35, 75, 25, "x1");
      nl_x1->color((Fl_Color)48);
      nl_x1->textcolor((Fl_Color)FL_SELECTION_COLOR);
    } // Fl_Output* nl_x1
    { nl_x2 = new Fl_Output(135, 35, 75, 25, "x2");
      nl_x2->color((Fl_Color)48);
      nl_x2->textcolor((Fl_Color)FL_SELECTION_COLOR);
    } // Fl_Output* nl_x2
    { nl_y1 = new Fl_Output(25, 65, 75, 25, "y1");
      nl_y1->color((Fl_Color)48);
      nl_y1->textcolor((Fl_Color)FL_SELECTION_COLOR);
    } // Fl_Output* nl_y1
    { nl_y2 = new Fl_Output(135, 65, 75, 25, "y2");
      nl_y2->color((Fl_Color)48);
      nl_y2->textcolor((Fl_Color)FL_SELECTION_COLOR);
    } // Fl_Output* nl_y2
    { nl_slope = new Fl_Output(55, 100, 95, 25, "Slope:");
      nl_slope->color((Fl_Color)48);
      nl_slope->textcolor((Fl_Color)FL_SELECTION_COLOR);
    } // Fl_Output* nl_slope
    { Fl_Group* o = new Fl_Group(150, 35, 160, 90);
      { nl_slope_unit = new Fl_Output(150, 100, 160, 25);
        nl_slope_unit->box(FL_NO_BOX);
        nl_slope_unit->textsize(12);
      } // Fl_Output* nl_slope_unit
      { nl_xunit = new Fl_Output(215, 35, 95, 25);
        nl_xunit->box(FL_NO_BOX);
        nl_xunit->textsize(12);
      } // Fl_Output* nl_xunit
      { nl_yunit = new Fl_Output(215, 65, 95, 25);
        nl_yunit->box(FL_NO_BOX);
        nl_yunit->textsize(12);
      } // Fl_Output* nl_yunit
      o->end();
    } // Fl_Group* o
    { line_display = new Fl_Browser(10, 155, 295, 165);
      line_display->type(1);
      line_display->callback((Fl_Callback*)cb_line_display);
      Fl_Group::current()->resizable(line_display);
    } // Fl_Browser* line_display
    { Fl_Button* o = new Fl_Button(10, 325, 295, 20, "dismiss");
      o->callback((Fl_Callback*)cb_dismiss1);
    } // Fl_Button* o
    { Fl_Box* o = new Fl_Box(10, 136, 32, 14, "# Slope Yintercept Xintercept");
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    } // Fl_Box* o
    nl_info_win->end();
  } // Fl_Double_Window* nl_info_win
}
