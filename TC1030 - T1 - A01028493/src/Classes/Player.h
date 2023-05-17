class Player {
  private:
   int id;
   int currentTile = 0;

  public:
   Player(int id) { id = 1; }

   void moveTiles(int tiles) { currentTile += tiles; }
};
