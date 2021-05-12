#include <iostream>
#include <memory>

//remote node lib h file
class RemoteNode{
public:
    void MsgRed(std::string msg)    const;
    void MsgBlue(std::string msg)   const;
    void MsgGreen(std::string msg)  const;
    void MsgYellow(std::string msg) const;

};
//remote node lib cpp file

void RemoteNode::MsgRed(std::string msg) const
{
    std::cout << "Red -> " << msg << std::endl;
}

void RemoteNode::MsgBlue(std::string msg) const
{
    std::cout << "Blue -> " << msg << std::endl;
}

void RemoteNode::MsgGreen(std::string msg) const
{
    std::cout << "Green -> " << msg << std::endl;
}

void RemoteNode::MsgYellow(std::string msg) const
{
    std::cout << "Yellow -> " << msg << std::endl;
}
class LocalNode {
public:
    enum Color {
        Red = 0,
        Blue,
        Green,
        Yellow
    };

   virtual void Message(Color color, std::string msg) = 0; 
};

//Note: nodes are the same with different approach

class NodeAdapter : public LocalNode, public RemoteNode{
  virtual void Message(Color color, std::string msg)
  {
      switch (color)
      {
      case Red:
          MsgRed(msg);
          break;
      case Blue:
          MsgBlue(msg);
          break;
      case Green:
          MsgGreen(msg);
          break;
      case Yellow:
          MsgYellow(msg);
          break;        
      default:
          std::cout << "unsuported" << std::endl;
          break;
      }
  }  
};
int main(int argc, char *argv[]) 
{
    std::unique_ptr<LocalNode> nodePtr(new NodeAdapter()); //interface local
    nodePtr->Message(nodePtr->Red,    "test red");
    nodePtr->Message(nodePtr->Blue,   "test blue");
    nodePtr->Message(nodePtr->Green,  "test red");
    nodePtr->Message(nodePtr->Yellow, "test blue");
    
}