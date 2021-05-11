#ifndef PROGRESSBARANIMATION_H
#define PROGRESSBARANIMATION_H
#include <QProgressBar>

/*!
*   \brief
*/
enum class AnimationStyles
{
    START = 0,/*!< */
    CONTINUE/*!< */
};
/*!
*   \brief
*/
class ProgressBarAnimation
{
private:
    QProgressBar* bar;/*!< */
    bool marker;/*!< */
    AnimationStyles style;/*!< */

    void rigth_left_start_animation();
    void rigth_left_continue_animation();
public:
    ProgressBarAnimation(QProgressBar* bar,AnimationStyles style = AnimationStyles::START);
    void animate();
};

#endif // PROGRESSBARANIMATION_H
