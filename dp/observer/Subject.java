package dp.observer;
import  java.util.*;

interface Subject {
	boolean addObserver(Observer o);
	boolean removeObserver(Observer o);
	void notifyObservers();
	void setChange(int temperatureIn, int humidityIn, int windSpeedIn);
}

	
		
