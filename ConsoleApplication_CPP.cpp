// ConsoleApplication_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class TaskResource  // vector and id
{
public:
    TaskResource(int id)
    {
        this->id = id;
    }

    void doTask(std::string task)
    {
        taskVector.push_back(task);
    }

    size_t countTasks() const
    {
        return taskVector.size();
    }

    std::string getTask(int index) const
    {
        return taskVector.at(index);
    }

    //void remvoeTask(int index) const
    //{
    //    return taskVector.delete(index);
    //}
private:
    std::vector<std::string> taskVector;
    int id;
};

class Worker// no error
{
public:
    TaskResource* acquireTaskResource(int id)
    {
        // key position in the map key, if found, else maybe return othern vaue
        std::unordered_map<int, TaskResource*>::iterator search = resourceMap.find(id);  // return if key is found
        // if key is found, iterator of that element is teturned
        // if not found, one pass the last iterator value is returned i.e. resourceMap.end()
        if (search == resourceMap.end())  // not found key
        {
            TaskResource* taskResource = new TaskResource(id);
            std::pair<int, TaskResource*> keyValue(id, taskResource);
            resourceMap.insert(keyValue);
            return taskResource;  // This taskResource disppear after function exit, pointer exist
        }
        else //found element
        {
            return search->second;
        }
    }

    void releaseTaskResource(int id)
    {
        std::unordered_map<int, TaskResource*>::iterator search = resourceMap.find(id);
        // release TaskResource's internal vector memory
        if (search == resourceMap.end())  // not found key
        {
            // do nothign
        }
        else
        {

            delete search->second;  // desturct TaskResource object
            //(search->second)->remvoeTask(id);
        }     
        resourceMap.erase(id);
    }

private:
    std::unordered_map<int, TaskResource*> resourceMap;
};

#ifndef RunTests
void printTaskResource(const TaskResource& taskResource)
{
    for (size_t i = 0; i < taskResource.countTasks(); i++)
    {
        if (i != 0)
        {
            std::cout << ", ";
        }

        std::cout << taskResource.getTask(i);
    }
    std::cout << '\n';
}

int main()
{
    Worker d;

    d.acquireTaskResource(1)->doTask("Task11");
    d.acquireTaskResource(2)->doTask("Task21");
    //printTaskResource(*d.acquireTaskResource(2));    
    d.acquireTaskResource(1)->doTask("Task12");

    printTaskResource(*d.acquireTaskResource(1));
    //std::cout << (*d.acquireTaskResource(1));
    printTaskResource(*d.acquireTaskResource(2));
    d.releaseTaskResource(1);

    
    cout << "object is nullptr or not" << d.acquireTaskResource(1) << endl;
}
#endif


//Structure:  Worker access TasREsource class internally
// printTaskResource