## Design

#### Racer problem

Imagine a race with R racers and S sensors are regular intervals along the race track. Design a
system that can process a "tick" (a combination of racer Rx crossing sensor Sy) at a time and that
can determine who is winning at the moment in constant time

#### Interconnected servers

Given an interconnected cluster of computers, design a system where a single script can be deployed
to a single origin machine that must then communicate (to itself and) to all of the other machines
that that script needs to be executed.

(Modification) Multiple different scripts can be deployed to different origin machines and need to
communicate execution.

(Modification) A single script might need to be run multiple times, but the instruction is given at
different times and the same script might be deployed to different origin machines during each request.

#### Interconnected servers

Assume that you're building a system of servers. You have a list of servers numbers (starting from 1)
that represent the server names that have been taken. Find the earliest

(Modification) Assume that you're trying to build a class NOT FINISHED*****

#### LRU Cache

Implement a least recently used (LRU) cache. This structure should provide the normal get value for
key and set value for key functions. The cache has a capacity. Once you hit the capacity and try to
add another key/value pair, then you remove key/value pair accessed the longest time ago.

Solution
Keep a hash table of key/value pairs and also keep a priority queue of key/timestamp pairs, with
the timestamp representing either when it was first added or when it was last accessed via get.

#### Wedding Appetizer Table

Imagine a party that has a table of appetizers containing individual plates of vegetable, shrimp,
and beef appetizers. The server behind the table has an interest in giving the oldest dish available
at that table, so as to prevent food poisoning by keeping a dish around longer than it needs to be.
The server can replenish the stock of each appetizer, one dish at a time. A guest can come up to the
table and request one specific appetizer. However, a guest might also not care what he/she receives,
and can therefore request that the server choose the dish themselves. Design and implement a system
that satisfies all of these needs.

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
