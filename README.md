Weather Forecasting and Historical Data Application
Overview
This application provides functionalities to fetch and display current weather data and historical weather data. It also supports exporting the data to CSV and JSON formats. The application uses the Open Meteo API for weather forecasts and other APIs for historical weather data.
Code Documentation
1. WeatherForecastingSystem Class
•	Purpose: Handles fetching and displaying current weather data. Also supports exporting data to CSV and JSON formats.
•	Constructor:
	Cpp code:
WeatherForecastingSystem(const string& apiKey, const string& baseUrl)
o	Parameters:
	apiKey: API key for authentication.
	baseUrl: Base URL of the weather forecast API.
•	Methods:
o	string fetchWeatherData(const string& location)
	Fetches weather data for the specified location.
	Parameters:
	location: City name or location for weather data.
	Returns: Weather data in JSON format.
o	void displayWeatherData(const string& data)
	Displays fetched weather data on the console.
	Parameters:
	data: Weather data in JSON format.
o	void exportWeatherDataToCSV(const string& data, const string& filename)
	Exports weather data to a CSV file.
	Parameters:
	data: Weather data to be exported.
	filename: Name of the CSV file.
o	void exportWeatherDataToJSON(const string& data, const string& filename)
	Exports weather data to a JSON file.
	Parameters:
	data: Weather data to be exported.
	filename: Name of the JSON file.
2. HistoricalWeatherSystem Class
•	Purpose: Handles fetching and displaying historical weather data.
•	Constructor:

	Cpp code:
HistoricalWeatherSystem(const string& apiKey, const string& baseUrl, const string& historicalBaseUrl)

o	Parameters:
	apiKey: API key for authentication.
	baseUrl: Base URL of the weather API.
	historicalBaseUrl: Base URL of the historical weather data API.
•	Methods:
o	string fetchHistoricalWeatherData(const string& location, const string& date)
	Fetches historical weather data for the specified location and date.
	Parameters:
	location: City name or location for historical data.
	date: Date in YYYY-MM-DD format.
	Returns: Historical weather data in JSON format.
o	void displayHistoricalWeatherData(const string& data)
	Displays fetched historical weather data on the console.
	Parameters:
	data: Historical weather data in JSON format.
Setup and Running the Application
1.	Prerequisites:
o	Ensure you have the cURL library installed and properly configured.
o	Include the nlohmann/json library for JSON handling.
2.	Configuration:
o	Replace placeholder API keys in the main function with your actual API keys.
o	Ensure the URLs for the forecast and historical weather APIs are correct.
3.	Compilation:
o	Use a C++ compiler that supports C++11 or later.
o	Compile the code with appropriate flags to link against the cURL and JSON libraries. For example:

	Copy code
g++ -o weather_app main.cpp -lcurl –ljson

4.	Running the Application:
o	Execute the compiled application from the command line:

	Copy code
./weather_app
o	The application will fetch current weather data for London, display it, and export it to CSV and JSON files. It will also fetch and display historical weather data for a specified date.
Functionality
•	Current Weather:
o	Fetches current weather data from the Open Meteo API.
o	Displays weather data on the console.
o	Exports data to current_weather.csv and current_weather.json.
•	Historical Weather:
o	Fetches historical weather data from the specified historical weather data API.
o	Displays historical weather data on the console.
Sample Output
•	Console Output:
	Css code
Weather Data: {"temperature_2m_max":22.5,"temperature_2m_min":15.8}
Historical Weather Data: {"temperature_max":21.0,"temperature_min":14.0}
•	CSV File (current_weather.csv):

	Json code
weather_data
{"temperature_2m_max":22.5,"temperature_2m_min":15.8}

•	JSON File (current_weather.json):

	Json code:
{"temperature_2m_max":22.5,"temperature_2m_min":15.8}

Troubleshooting
•	File Not Found Errors:
o	Ensure file paths are correct and that you have write permissions in the directory.
•	API Errors:
o	Check if your API keys are valid and not expired.
o	Verify that the API endpoints are correct and reachable.



----------------------------------------
# DEP
