#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

//#define USE_SHARED_PTR

class Worker {
	friend std::ostream& operator<<(std::ostream& out, const Worker& wrr);
public:
	Worker(const char* name_ = "Unknown") : name(name_) {};
	~Worker() { std::cout << name << " deleted" << std::endl; };
	void set_leader(std::shared_ptr<Worker> leader_) 
	{ 
		leader = leader_; 
	};
	void add_worker(std::shared_ptr<Worker> wr) { team.push_back(wr); };
	void remove(int count)
	{
		while (count-- > 0 && team.size() > 0)
			team.pop_back();
	};
	const std::string& GetName() const { return name; };
	static void join_team(std::shared_ptr<Worker> leader, std::shared_ptr<Worker> wr) {
		leader->add_worker(wr);
		wr->set_leader(leader);
	};
private:
	std::string name;
#ifdef USE_SHARED_PTR
	std::shared_ptr<Worker> leader;
#else
	std::weak_ptr<Worker> leader;
#endif // USE_SHARED_PTR

	std::vector<std::shared_ptr<Worker>> team;
};


std::ostream& operator<<(std::ostream& out, const Worker& wr)
{
#ifdef USE_SHARED_PTR
	std::cout << "I am " << wr.GetName() << ". My leader is " << (wr.leader == nullptr ? "no-one" : wr.leader->GetName()) << std::endl;
#else
	std::shared_ptr<Worker> ldr = wr.leader.lock(); // get shared pointer from weak pointer - will return nullptr if shared pointer no longer exists
	std::cout << "I am " << wr.GetName() << ". My leader is " << (ldr == nullptr ? "no-one" : ldr->GetName()) << std::endl;
#endif // USE_SHARED_PTR

	if (wr.team.size() > 0) {
		std::cout << wr.GetName() << "'s team is: " << std::endl;
		for (auto& wptr : wr.team) { std::cout << *wptr; };
		std::cout << "End of " << wr.GetName() << "'s team" << std::endl;
	}

	return out;
}

void print(std::shared_ptr<Worker> wr) {
	std::cout << "---------------" << std::endl;
	std::cout << *wr;
	std::cout << "---------------" << std::endl;
}

void play_got()
{
	std::cout << "Game of Thrones started" << std::endl;

	std::shared_ptr<Worker> robert(new Worker("Robert Baratheon"));
	{
		std::shared_ptr<Worker> barristan(new Worker("Barristan Selmy"));
		std::shared_ptr<Worker> ned(new Worker("Ned Stark"));
		std::shared_ptr<Worker> ed(new Worker("Dolorous Ed"));
		auto jon = std::make_shared<Worker>("Jon Snow");
		Worker::join_team(ned, ed);
		Worker::join_team(ned, jon);
		Worker::join_team(robert, ned);
		Worker::join_team(robert, barristan);
	}
	print(robert);
	robert->remove(1);
	print(robert);

	std::cout << "Game of thrones ended" << std::endl;

}

int main(int argc, char** argv) {
	play_got();

	return 0;
}