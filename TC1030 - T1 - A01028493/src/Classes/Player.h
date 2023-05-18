
class Player {
  private:
   int id;
   int currentTile = 0;

  public:
   Player(int id = 0) { id = 1; }

   void moveTiles(int tiles) { currentTile += tiles; }
};
