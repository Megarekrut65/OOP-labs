#include "progress_bar_animation.h"

ProgressBarAnimation::ProgressBarAnimation(QProgressBar* bar,AnimationStyles style):
    bar(bar),marker(false),style(style){}
void ProgressBarAnimation::rigth_left_start_animation()
{
    int value = bar->value();
    if(value == bar->maximum())
    {
        if(marker)marker = false;
        else marker = true;
        bar->setInvertedAppearance(marker);
    }
    bar->setValue((value + 1)%(bar->maximum()+1));
}
void ProgressBarAnimation::rigth_left_continue_animation()
{
    int value = bar->value();
    if(value == bar->maximum()||(value == bar->minimum() && marker))
    {
        if(marker)marker = false;
        else marker = true;
        bar->setInvertedAppearance(marker);
    }
    if(marker) bar->setValue(value - 1 < bar->minimum()?bar->minimum():value - 1);
    else bar->setValue(value + 1 > bar->maximum()?bar->maximum():value + 1);
}
void ProgressBarAnimation::animate()
{
    if(!bar) return;
    switch (style)
    {
        case AnimationStyles::START:rigth_left_start_animation();
        break;
        case AnimationStyles::CONTINUE:rigth_left_continue_animation();
        break;
    default:
        break;
    }
}
