import requests


def translate_input(user_input):
    data = {
        'userInput': user_input,
        'labDataContext': {
            'labItemName': None,
            'labUnit': None,
            'labSampleType': None,
            'labTotalRecords': None,
            'labUniquePatients': None,
            'labMissingValues': None,
            'labMeanValue': None,
            'labMedianValue': None,
            'itemRank': None,
            'institution': None,
            'institutionType': None,
            'institutionLocation': None,
            'itemId': None,
            'dataSource': None,
            'timestamp': None,
            'source': 'url_parameters'
        }
    }
    url = 'https://search.loinc100.org/api/translate-input'
    response = requests.post(url, json=data)
    return response.json()


def search(field1, field2):
    data = {
        'field1': field1,
        'field2': field2,
        'componentField': 'Creatinine',
        'systemField': 'Blood',
        'useOrderRankFilter': False,
        'useTestRankFilter': True,
        'labDataContext': {
            'labItemName': None,
            'labUnit': None,
            'labSampleType': None,
            'labTotalRecords': None,
            'labUniquePatients': None,
            'labMissingValues': None,
            'labMeanValue': None,
            'labMedianValue': None,
            'itemRank': None,
            'institution': None,
            'institutionType': None,
            'institutionLocation': None,
            'itemId': None,
            'dataSource': None,
            'timestamp': None,
            'source': 'url_parameters'
        }
    }
    url = 'https://search.loinc100.org/api/search'
    response = requests.post(url, json=data)
    return response.json()


def main():
    translated = translate_input('Creatinine')
    print(translated)
    results = search('Creatinine Blood', 'Creatinine')
    print(results)


if __name__ == '__main__':
    main()
