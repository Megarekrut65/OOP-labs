#ifndef PROGRESSBARANIMATION_H
#define PROGRESSBARANIMATION_H
#include <QProgressBar>

/*!
*   \brief Styles of animation
*/
enum class AnimationStyles
{
    START = 0,/*!< First style */
    CONTINUE/*!< Secons style */
};
/*!
*   \brief Class to create some animations of progress bar
*/
class ProgressBarAnimation
{
private:
    QProgressBar* bar;/*!< Pointer to progress bar*/
    bool marker;/*!< Shows maximum or minimum value step of progress bar*/
    AnimationStyles style;/*!< Selected style */
    /*!
    *   \brief First animation
    */
    void rigth_left_start_animation();
    /*!
    *   \brief Second animation
    */
    void rigth_left_continue_animation();
public:
    /*!
    *   \brief Adds bar to class and selected style
    */
    ProgressBarAnimation(QProgressBar* bar,AnimationStyles style = AnimationStyles::START);
    /*!
    *   \brief Calls one of all animation of progress bar
    */
    void animate();
};

#endif // PROGRESSBARANIMATION_H
