#include "ActionInitialization.hh"
#include "EventAction.hh"
#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh" 

#ifdef MPI
#include "MPIRunActionMaster.hh"
#endif

MyActionInitialization::MyActionInitialization(){}


MyActionInitialization::~MyActionInitialization(){}

void MyActionInitialization::BuildForMaster() const
{
	#ifndef MPI
	SetUserAction(new RunAction());	
	#else
	SetUserAction(new RunActionMaster(true));
	#endif
}

void MyActionInitialization::Build() const
{
	PrimaryGeneratorAction* generator = new PrimaryGeneratorAction("");
	
	#ifndef MPI
	SetUserAction(new RunAction());	
	#else
	SetUserAction(new RunActionMaster(true));
	#endif
	
	SetUserAction(new EventAction());
	SetUserAction(generator);
}

