#include "mysounds.h"

QVector<QString> MySounds::sounds = {"Sound1", "Sound2", "Sound3", "Sound4"};

int MySounds::get_index_of_sound(const QString &pathToSound)
{
    for(int i = 0; i < sounds.size(); i++)
    {
        if(pathToSound.contains(sounds[i])) return i;
    }
    return 0;
}
