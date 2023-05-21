
class Player {
  private:
   int id;
   int currentTile = 0;

  public:
   Player(int id = 0) { this->id = id; }

   void setId(int id = 0) { this->id = id; }
   void setTile(int tile = 0) { currentTile = tile; }

   void incrementTile(int tiles = 0) { currentTile += tiles; }
   int getTile() { return currentTile; }
};
