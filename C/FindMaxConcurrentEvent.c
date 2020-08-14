#include<stdio.h>
#include<malloc.h>

#define NOOFHOURSINADAY 24
#define NOOFEVENTS 9
// Events happens during the day. i.e., max 24 hours we need to account for.

typedef struct Event {
	int startTime;
	int endTime;
} Event;

typedef struct ConcurrentEvent {
	Event event;
	struct ConcurrentEvent* next;
} ConcurrentEvent;

void AddEvent(Event* array, int count, int startTime, int endTime) {
	struct Event event;
        event.startTime = startTime;
        event.endTime = endTime;
        array[count] = event;
}

void GetEvents(Event* array, int* numberOfEvents) {
	int count = 0;
	AddEvent(array, count++, 1,5);
        AddEvent(array, count++, 6,10);
        AddEvent(array, count++, 11,13);
        AddEvent(array, count++, 14,15);
        AddEvent(array, count++, 2,7);
        AddEvent(array, count++, 8,9);
        AddEvent(array, count++, 12,15);
        AddEvent(array, count++, 4,5);
        AddEvent(array, count++, 9,17);
	
	*numberOfEvents = count;
}

void GetIntersectionOfEvents(Event* array, int numberOfEvents) {
	int count = 0, noOfHours = NOOFHOURSINADAY;
	ConcurrentEvent* numberOfHours[noOfHours];
	while(count < noOfHours)
		numberOfHours[count++] = NULL;
	count = 0;
	while(count < numberOfEvents) {
		Event event = array[count++];		
		int startTime = event.startTime;
		int endTime = event.endTime;
		while(startTime <= endTime) {
			ConcurrentEvent* temp = (numberOfHours[startTime]);
			ConcurrentEvent* newNode = malloc(sizeof(ConcurrentEvent)); // need to create new nodes for each of the hour.
                        newNode->event = event;

			if(!temp)
				(numberOfHours[startTime]) = newNode;
			else {
				while(temp->next)
					temp = temp->next;
				temp->next = newNode;
			}
		
			startTime++;
		}
	}

	count = 0;
	int maxConcurrentEvents = -1;
	int countEvents;
	while(count < noOfHours) {
		if(numberOfHours[count] && (numberOfHours[count])->next) {
			ConcurrentEvent* node = numberOfHours[count];
			printf("Concurrent Events at Hour %d for ", count);
			countEvents = 0;
			while(node) {
				countEvents++;
				printf("Event(%d, %d), ", node->event.startTime, node->event.endTime);
				node = node->next;
			}
			if(countEvents > maxConcurrentEvents)
				maxConcurrentEvents = countEvents;
			printf("\n");
		}
		
		count++;
	}

	printf("Count Of Max Concurrent Events = %d\n", maxConcurrentEvents);
}

void main() {
	int numberOfEvents = NOOFEVENTS;
	Event array[numberOfEvents];
	GetEvents(array, &numberOfEvents);
	GetIntersectionOfEvents(array, numberOfEvents);
}
