#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
//#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <iostream>

using namespace std;

class threaded_class
{
public:
    threaded_class()
        : m_stoprequested(false), count_(1)
    {
    }
 
    ~threaded_class()
    {
    }
 
    // Create the thread and start work
    void Start() 
    {
        m_thread = boost::shared_ptr<boost::thread>(new boost::thread(boost::bind(&threaded_class::do_work, this)));
    }
 
    void Stop() // Note 1
    {
        m_stoprequested = true;
        m_thread->join();
    }
    
    int getCount() {
        return count_;
    }
 
 
private:
    volatile bool m_stoprequested;
    boost::shared_ptr<boost::thread> m_thread;
    //boost::mutex m_mutex;
    int count_;
 
 
    // Compute and save fibonacci numbers as fast as possible
    void do_work()
    {
        int iteration = 0;
        while (!m_stoprequested)
        {
            //boost::mutex::scoped_lock l(m_mutex);
            count_++;
        }
    }                    
};


main (int argc, char ** argv)
{
    threaded_class t;
    t.Start();
    sleep(5);
    cout << t.getCount() << endl;

    t.Stop();
    
    cout << t.getCount() << endl;

}
