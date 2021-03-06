// generated by Fast Light User Interface Designer (fluid) version 1.0107

#include "ThresholdDisplay_Control.h"
#include "ThresholdDisplay.H"

void ThresholdDisplay_Control::cb_dismiss_i(Fl_Button*, void*) {
  win->hide();
}
void ThresholdDisplay_Control::cb_dismiss(Fl_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->user_data()))->cb_dismiss_i(o,v);
}

void ThresholdDisplay_Control::cb_low_i(Fl_Value_Input*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_low(Fl_Value_Input* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->user_data()))->cb_low_i(o,v);
}

void ThresholdDisplay_Control::cb_high_i(Fl_Value_Input*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_high(Fl_Value_Input* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->user_data()))->cb_high_i(o,v);
}

void ThresholdDisplay_Control::cb_image_i(Fl_Round_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_image(Fl_Round_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->parent()->user_data()))->cb_image_i(o,v);
}

void ThresholdDisplay_Control::cb_line_i(Fl_Round_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_line(Fl_Round_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->parent()->user_data()))->cb_line_i(o,v);
}

void ThresholdDisplay_Control::cb_col_i(Fl_Round_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_col(Fl_Round_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->parent()->user_data()))->cb_col_i(o,v);
}

void ThresholdDisplay_Control::cb_val_i(Fl_Check_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_val(Fl_Check_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->parent()->user_data()))->cb_val_i(o,v);
}

void ThresholdDisplay_Control::cb_percent_i(Fl_Check_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_percent(Fl_Check_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->parent()->user_data()))->cb_percent_i(o,v);
}

void ThresholdDisplay_Control::cb_enable_i(Fl_Light_Button*, void*) {
  refresh();
}
void ThresholdDisplay_Control::cb_enable(Fl_Light_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->user_data()))->cb_enable_i(o,v);
}

void ThresholdDisplay_Control::cb_color_i(Fl_Button*, void*) {
  uchar r,g,b;
if (fl_color_chooser("Color", r, g, b))
{
   td->r=r; td->g=g; td->b=b;
}
refresh();
}
void ThresholdDisplay_Control::cb_color(Fl_Button* o, void* v) {
  ((ThresholdDisplay_Control*)(o->parent()->user_data()))->cb_color_i(o,v);
}

ThresholdDisplay_Control::ThresholdDisplay_Control(ThresholdDisplay *tdp) {
  Fl_Double_Window* w;
  td = tdp;
  { Fl_Double_Window* o = win = new Fl_Double_Window(295, 90, "Threshold Display");
    w = o;
    o->user_data((void*)(this));
    { Fl_Button* o = new Fl_Button(225, 65, 65, 20, "dismiss");
      o->labelsize(11);
      o->callback((Fl_Callback*)cb_dismiss);
    }
    { Fl_Value_Input* o = low = new Fl_Value_Input(45, 10, 100, 20, "Low:");
      o->maximum(100);
      o->value(2);
      o->callback((Fl_Callback*)cb_low);
      o->when(FL_WHEN_ENTER_KEY);
    }
    { Fl_Value_Input* o = high = new Fl_Value_Input(190, 10, 100, 20, "High:");
      o->maximum(100);
      o->value(90);
      o->callback((Fl_Callback*)cb_high);
      o->when(FL_WHEN_ENTER_KEY);
    }
    { Fl_Group* o = new Fl_Group(110, 40, 200, 15);
      { Fl_Round_Button* o = image = new Fl_Round_Button(110, 40, 70, 15, "Image");
        o->type(102);
        o->down_box(FL_ROUND_DOWN_BOX);
        o->callback((Fl_Callback*)cb_image);
      }
      { Fl_Round_Button* o = line = new Fl_Round_Button(180, 40, 70, 15, "Line");
        o->type(102);
        o->down_box(FL_ROUND_DOWN_BOX);
        o->value(1);
        o->callback((Fl_Callback*)cb_line);
      }
      { Fl_Round_Button* o = col = new Fl_Round_Button(240, 40, 70, 15, "Col");
        o->type(102);
        o->down_box(FL_ROUND_DOWN_BOX);
        o->callback((Fl_Callback*)cb_col);
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(5, 35, 70, 75);
      { Fl_Check_Button* o = val = new Fl_Check_Button(5, 65, 70, 15, "Value");
        o->type(102);
        o->down_box(FL_DOWN_BOX);
        o->callback((Fl_Callback*)cb_val);
      }
      { Fl_Check_Button* o = percent = new Fl_Check_Button(5, 40, 70, 15, "Percentile:");
        o->type(102);
        o->down_box(FL_DOWN_BOX);
        o->value(1);
        o->callback((Fl_Callback*)cb_percent);
      }
      o->end();
    }
    { Fl_Light_Button* o = enable = new Fl_Light_Button(90, 65, 64, 20, "Enable");
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_enable);
    }
    { Fl_Button* o = new Fl_Button(160, 65, 60, 20, "color...");
      o->labelsize(12);
      o->callback((Fl_Callback*)cb_color);
    }
    o->end();
  }
}

void ThresholdDisplay_Control::refresh() {
  td->iw->damage(FL_DAMAGE_OVERLAY);
td->iw->redraw_overlay();
}
