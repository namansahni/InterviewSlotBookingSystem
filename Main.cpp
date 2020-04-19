#include<iostream>
#include<vector>
using namespace std;

class Person { // base class
public:
	int id;
	string name;
	// other attributes: address, gender, etc

	Person();

	virtual int getId();

	virtual void setId(int id);

	virtual string getName();

	virtual void setName(string name);
};

class Attendee : public Person { // derived class 1
private: 

public:
	Attendee();

	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}

	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Interviewer : public Person { // derived class 2
private: 

public:
	Interviewer();

	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}

	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};

enum BlockList { // rooms can be in different blocks
	A_BLOCK,
	B_BLOCK,
	C_BLOCK,
	D_BLOCK
};

class Room {
private:
	int RoomNo;
	BlockList Block;
	int size = 2; // max people that can be accomodated
public:
	Room();
	
	void setRoomNo(int RoomNo) {
		this->RoomNo = RoomNo;
	}
	int getRoomNo() {
		return RoomNo;
	}
	void setBlock(BlockList Block) {
		this->Block = Block;
	}
	BlockList getBlock() {
		return Block;
	}
	int getSize() {
		return size;
	}
};
enum TimeSlots {
	_9_11,
	_11_1,
	_3_5
};

class InterviewSystem {
private:
	Attendee attendee;
	Interviewer interviewer;
	Room room;
	int maxTimeSlots = 3;
	TimeSlots currenttimeslot;

public:
	InterviewSystem() { // constructor
		// TimeSlots[0] = "9-11";
		// TimeSlots[1] = "11-1";
		// TimeSlots[2] = "3-5";
	}
	int getmaxTimeSlots() {
		return maxTimeSlots;
	}
	InterviewSystem(Attendee attendee, Interviewer interviewer, Room room, TimeSlots currenttimeslot) {
		this->attendee = attendee;
		this->interviewer = interviewer;
		this->room = room;
		this->currenttimeslot = currenttimeslot;
	}

	void settimeslot(TimeSlots currenttimeslot) {
		this->currenttimeslot = currenttimeslot;
	}
	TimeSlots gettimeslot() {
		return currenttimeslot;
	}


	void setattendee(Attendee attendeecpy) {
		attendee.setId(attendeecpy.getId());
		attendee.setName(attendeecpy.getName());
	}
	Attendee getattendee() {
		return attendee;
	}
	void setinterviewer(Interviewer interviewercpy) {
		interviewer.setId(interviewercpy.getId());
		interviewer.setName(interviewercpy.getName());
	}
	Interviewer getinterviewer() {
		return interviewer;
	}
	Room getroom() {
		return room;
	}
	void setroom(Room roomcpy) {
		room.setRoomNo(roomcpy.getRoomNo());
		room.setBlock(roomcpy.getBlock());

	}

	// void updateSchedule() {

	// }

};

int main() {
	
	vector<Attendee> attendee;
	vector<Interviewer> interviewer;
	vector<Room> room;
	vector<InterviewSystem> interviewsystemmain;
	vector<TimeSlots> timeslot;

	// input values --->
	Attendee tempattendee;
	tempattendee.setId(1);
	tempattendee.setName("name1");
	attendee.push_back(tempattendee);



	int i = 0;
	int maxtslots = interviewsystemmain[0].getmaxTimeSlots();

		
		for(int j=0;j<maxtslots;j++) {
			for(int k=0, x=0;k<room.size(), x<interviewer.size();k++) {
				if(i==attendee.size()) {
					cout<<"\n finished.";
					break;
				}
				InterviewSystem interviewsystem(attendee[i++], interviewer[x], room[k], timeslot[j]);
				interviewsystemmain[i].setinterviewer(interviewer[x]);
				interviewsystemmain[i].setroom(room[k]);
				interviewsystemmain[i].settimeslot(timeslot[j]);

			}
		}

		while(i!=attendee.size()) {
		cout<<endl<<"Attendee "<<i<<" unfortunately can not be interviewed. \n";
		i++;
	}

	return 0;
}
























// class InterviewProcess {
// private:
// 	vector<Attendee> attendee;
// 	vector<Interviewer> interviewer;
// 	vector<Room> room;
// 	vector<string> TimeSlots;
// 	const int maxTimeSlots = 3;
// public:
// 	InterviewProcess() { // constructor
// 		TimeSlots[0] = "9-11";
// 		TimeSlots[1] = "11-1";
// 		TimeSlots[2] = "3-5";
// 	}
// 	void setattendee(vector<Attendee> attendee) {
// 		this->attendee = attendee;
// 	}
// 	vector<Attendee> getattendee() {
// 		return attendee;
// 	}
// 	void setinterviewer(vector<Interviewer> interviewer) {
// 		this->interviewer = interviewer;
// 	}
// 	vector<Interviewer> getinterviewer() {
// 		return interviewer;
// 	}
// 	vector<Room> getroom() {
// 		return room;
// 	}
// 	void setroom(vector<Room> room) {
// 		this->room = room;
// 	}

// 	void updateSchedule() {
		
// 	}

// };