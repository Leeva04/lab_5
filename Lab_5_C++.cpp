#include <iostream>

using namespace std;


enum BugStatus
{
	NOT_RESOLVED,
	IN_PROCESS,
	RESOLVED
};

class Bug
{
private:
	int _bug_id = 0;
	string _description;
	int _severity_1_to_10 = 0;
	string _deadline;
	BugStatus _status = NOT_RESOLVED;
	string _assignee;
public:
	Bug() {}

	Bug(int bug_id, string description, int severity_1_to_10, string deadline, BugStatus status, string assignee) {
		_bug_id = bug_id;
		_description = description;
		_severity_1_to_10 = severity_1_to_10;
		_deadline = deadline;
		_status = status;
		_assignee = assignee;
	}

	int GetSeverity() {
		return _severity_1_to_10;
	}

	void SetSevetity(int value) {
		_severity_1_to_10 = value;
	}

	int GetId() {
		return _bug_id;
	}

	BugStatus GetStatus() {
		return _status;
	}
};
class Backlog
{
public:
	Backlog() {};

	Bug Bugs[5];

	void AddBugs(Bug arr[]) {
		for (int i = 0; i < 5; i++) {
			Bugs[i] = arr[i];
		}
	}

	void SortBugSeverity() {
		int temp;
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++)
			{
				if (Bugs[j].GetSeverity() < Bugs[i].GetSeverity()) {
					temp = Bugs[i].GetSeverity();
					Bugs[i].SetSevetity(Bugs[j].GetSeverity());
					Bugs[j].SetSevetity(temp);
				}
			}
		}

		cout << "Bug sevetiry by ascending:\n" << endl;

		for (int i = 0; i < 5; i++) {
			cout << Bugs[i].GetId() << " - " << Bugs[i].GetSeverity() << endl;
		}
	}

	void GetResolvedBugs() {
		int properBugsCount = 0;
		for (int i = 0; i < 5; i++) {
			if (Bugs[i].GetStatus() == RESOLVED) {
				properBugsCount++;
			}
		}

		Bug* temp = new Bug[properBugsCount];
		int place_in_temp = 0;
		for (int i = 0; i < 5; i++) {
			if (Bugs[i].GetStatus() == RESOLVED) {
				temp[place_in_temp] = Bugs[i];

				place_in_temp++;
			}
		}

		cout << "Resolved Bugs:\n" << endl;

		for (int i = 0; i < properBugsCount; i++) {
			cout << temp[i].GetId() << " - " << temp[i].GetStatus() << endl;
		}
	}
};

int main()
{
    Bug bug_1 (1,"Screen is in fire",3,"two days", BugStatus::NOT_RESOLVED, "David");
    Bug bug_2 (2, "Prod has been dropped", 7, "two hours", BugStatus::RESOLVED, "Kevin");
    Bug bug_3 (3, "Button is not working properly", 6, "one month", BugStatus::IN_PROCESS, "Olya");
    Bug bug_4 (4, "No internet connection in Ternopil", 2, "five minutes", BugStatus::RESOLVED, "Yura");
    Bug bug_5 (5, "Bad color on banner", 1, "one year", BugStatus::RESOLVED, "Oleg");

    Bug bugs[] = { bug_1, bug_2 ,bug_3 ,bug_4 ,bug_5 };

    Backlog backlog;
    backlog.AddBugs(bugs);
    backlog.GetResolvedBugs();
    cout << endl;
    backlog.SortBugSeverity();
    cout << endl;
}