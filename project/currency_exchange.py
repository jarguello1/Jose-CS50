"""
Code pulls data from the federal reserve exchange chart
and uses it to do rough currency conversions.
"""

#import library
import requests
import pandas as pd

#URL for the United States Federal Reserve Currency Exchange Data
url = 'https://www.federalreserve.gov/datadownload/Output.aspx?rel=H10&series=60f32914ab61dfab590e0e470153e3ae&lastobs=10&from=&to=&filetype=csv&label=include&layout=seriescolumn&type=package'
#Files to write data
filename = 'fed_exchange.csv'
test_file = 'fed_exchange2.csv'

#requests functions to gather data from the Federal Reserve
request = requests.get(url)
content = request.text

#Write requested data to csv file
with open(filename, 'w') as file:
	file.write(request.text)

#Use pandas to reduce data, only including the country, currency and value.
rows_to_skip = list(range(2,6)) + list(range(8,30))
df = pd.read_csv(filename, skiprows = rows_to_skip)
df = df.transpose()
df = df.reset_index()

#List for symbols of currencies that are presented in USD
extra_currencies = ['AUD', 'EUR', 'NZD', 'GBP']

print("\nThis program only converts to and from USD at the moment.")

# For loop to print all the currency options
for i in range(1,24):
	print(f"{i} {df.iloc[i]['index']}")

def get_currency():
	#Ask user which currency they want to convert to or from
	currency = 0
	while (currency < 1) or (currency > 23):
		currency = int(input("\nPlease input the currency you are converting. (1-23) "))
	return currency

def to_or_from():
	#request whether the user wants to convert to USD or from USD
	answer = ""
	while True:
		answer = input("\nWould you like to convert to USD or from USD? T/F ")
		if answer.lower() == "t" or answer.lower() == "f":
			break
	return answer


def convert_money(currency, answer):

	"""
	AUD, EUR, NZD, GBP values are presented in USD for the federal reserve so there has to be a separate if statement for these currencies.
	"""
	#Converts currencies to USD to respective currencies.

	amount = (input("\nPlease input that amount you would like to exchange? "))

	if currency in [1,2,3,4] and answer == 't':
		new_currency = float(amount) * float(df.iloc[int(currency)][1])
		print(f'{new_currency} {df.iloc[int(currency)][0]}')
		return new_currency

	elif currency > 4 and answer == 't':
		new_currency = float(amount) / float(df.iloc[int(currency)][1])
		print(f'{new_currency} {df.iloc[1][0]}')
		return new_currency

	elif currency in [1,2,3,4] and answer == 'f':
		"""
		AUD, EUR, NZD, GBP values are presented in USD for the federal reserve so there has to be a separate if statement for these currencies.
		"""
		#Converts currencies to USD to respective currencies.
		new_currency = float(amount) / float(df.iloc[int(currency)][1])
		#Subtract 1 from the currency value to obtain the right currency marker from the extra_currencies list.
		print(f'{new_currency} {extra_currencies[int(currency)-1]}')
		return new_currency

	elif currency > 4 and answer == 'f':
		new_currency = float(amount) * float(df.iloc[int(currency)][1])
		print(f'{new_currency} {df.iloc[int(currency)][0]}')
		return new_currency

requested_currency = get_currency()
to_from = to_or_from()
convert_money(requested_currency, to_from)