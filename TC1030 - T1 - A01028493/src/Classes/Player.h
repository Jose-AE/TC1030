
class Player {
  private:
   int id;
   int currentTile = 0;

  public:
   Player(int id = 0) { this->id = id; }

   void moveTiles(int tiles) { currentTile += tiles; }
};
