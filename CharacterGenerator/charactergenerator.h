#ifndef CHARACTERGENERATOR_H
#define CHARACTERGENERATOR_H

#include <QWidget>
#include <QList>

#include "playercharacter.h"
#include "diceroller.h"
#include "observer.h"
#include "statwindow.h"
#include "characterbuilder.h"

namespace Ui {
    class CharacterGenerator;
}

class CharacterGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterGenerator(QWidget *parent = 0);
    ~CharacterGenerator();

    void init();
    virtual void show();

private:
    Ui::CharacterGenerator *ui;
    StatWindow *mStatWindow;
    CharacterBuilder* mCharacterBuilder;

    void removeLowestValue(QList<int> &aList);
    //Director specific functions
    void setCharacterBuilder(CharacterBuilder* aCharacterBuilder);
    PlayerCharacter* player();
    void constructCharacter();

private slots:
    void changePicture();

    void rollAbilityScores();

    void generateCharacter();
    void readyToGenerate();
    void returnToMenuButtonPress();

    void saveCharacter();
    void reset();
};

#endif // CHARACTERGENERATOR_H
