#ifndef NOTE_H
#define NOTE_H
#include <QStringList>

class Note
{
private :
    QStringList Notes;
public:
    Note();
    QStringList getNotes() const { return this->Notes; }
};

#endif // NOTE_H
