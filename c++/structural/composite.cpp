#include <string>
#include <iostream>
#include <memory>
#include <vector>

class INode
{
public:
  INode(const std::string & _name) : name(_name) {}
  virtual ~INode() {}
  virtual void list() const = 0;

protected:
  const std::string name;
};

class Directory : public INode
{
public:
  Directory(const std::string & _name) : INode(_name)
  {}

  void list() const override
  {
    std::cout << name << std::endl;
    for(auto n : nodes)
    {
      n->list();
    }
  }
  
  void add(std::shared_ptr<INode> node)
  {
    nodes.push_back(node);
  }

private:
  std::vector<std::shared_ptr<INode> > nodes;
};

class File : public INode
{
public:
  File(const std::string & _name) : INode(_name)
  {}

  void list() const override
  {
    std::cout << name << std::endl;
  }
};


int main(int argc, const char ** argv)
{
  auto root = std::make_shared<Directory>("/");
  root->add(std::make_shared<Directory>("/tmp"));
  auto home = std::make_shared<Directory>("/home");
  root->add(home);
  auto joe = std::make_shared<Directory>("/home/joe");
  home->add(joe);
  auto dot_emacs = std::make_shared<File>("/home/joe/.emacs");
  joe->add(dot_emacs);
  auto documents = std::make_shared<Directory>("/home/joe/documents");
  joe->add(documents);
  auto readme_txt = std::make_shared<File>("/home/joe/Documents/readme.txt");
  documents->add(readme_txt);
  root->list();
}
