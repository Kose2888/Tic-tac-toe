#ifndef PLAYER_H
#define PLAYER_H

class Player {
  private:
    bool X;
    bool O;

  public:
    Player();

    ~Player();

    void setIsX(bool);

    void setIsO(bool);

    bool getX() const {return X;}

    bool getO() const {return O;}

    virtual int determineMove() = 0;  // Parameters TBD

};


#endif
