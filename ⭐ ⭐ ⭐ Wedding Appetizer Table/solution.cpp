struct Appetizer {
  string type;
  time_t creationTime;
};

class AppetizerTable {
private:

  vector<queue<Appetizer*>> appetizerQueues;
  unordered_map<string, int> appetizerQueueIndices;

public:

  void replenishAppetizer(const string& type)
  {
    Appetizer* appetizer = new Appetizer(type, getCurrentTime());
    int appetizerQueueIndex = appetizerQueueIndices[type];
    appetizerQueues[appetizerQueueIndex].push(appetizer);
  }

  Appetizer* serveAppetizer(const string& type)
  {
    int appetizerQueueIndex = appetizerQueueIndices[type];
    Appetizer* appetizer = appetizerQueues[appetizerQueueIndex].top();
    appetizerQueues[appetizerQueueIndex].pop();
    return appetizer;
  }

  Appetizer* serveAnyAppetizer()
  {
      int oldestAppetizerIndex = 0;
      Appetizer* currentOldestAppetizer;
      Appetizer* currentAppetizer;
      for (int i = 1; i < appetizerQueues.size(); ++i)
      {
        currentOldestAppetizer = appetizerQueues[oldestAppetizerIndex].top();
        currentAppetizer = appetizerQueues[i].top();
        if (currentOldestAppetizer.creationTime > currentAppetizer.creationTime)
        {
            oldestAppetizerIndex = i;
        }
      }
      Appetizer* appetizer = appetizerQueues[appetizerQueueIndex].top();
      appetizerQueues[appetizerQueueIndex].pop();
      return appetizer;
  }

}
