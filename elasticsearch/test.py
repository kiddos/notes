from elasticsearch import Elasticsearch
from elasticsearch.exceptions import ConnectionError, ApiError
from dotenv import dotenv_values

config = dotenv_values('.env')

host = "localhost"
port = 9200
username = config['ELASTICSEARCH_USERNAME']
password = config['ELASTICSEARCH_PASSWORD']
index_name = 'index1'
index_body = {
    "settings": {
        "number_of_shards": 1,  # Number of primary shards for the index
        "number_of_replicas": 0
    },
    "mappings": {
        "properties": {
            "title": {
                "type": "text",  # Text field for full-text search
                "analyzer": "standard"  # Standard analyzer for text processing
            },
            "author": {
                "type":
                "keyword"  # Keyword field for exact matching (e.g., filtering)
            },
            "publish_date": {
                "type": "date",  # Date field
                "format":
                "yyyy-MM-dd HH:mm:ss||yyyy-MM-dd"  # Supported date formats
            },
            "content": {
                "type": "text"
            },
            "tags": {
                "type": "keyword"
            }
        }
    }
}
documents = [{
    "title": "The Hitchhiker's Guide to the Galaxy",
    "author": "Douglas Adams",
    "publish_date": "1979-10-12",
    "content":
    "A comedic science fiction series created by Douglas Adams. Originally a radio comedy broadcast on BBC Radio 4 in 1978.",
    "tags": ["science fiction", "comedy", "radio"],
}, {
    "title": "Pride and Prejudice",
    "author": "Jane Austen",
    "publish_date": "1813-01-28",
    "content":
    "A romantic novel of manners written by Jane Austen in 1813. The novel follows the emotional development of protagonist Elizabeth Bennet.",
    "tags": ["romance", "classic", "fiction"]
}, {
    "title": "1984",
    "author": "George Orwell",
    "publish_date": "1949-06-08",
    "content":
    "A dystopian social science fiction novel and cautionary political satire by English author George Orwell.",
    "tags": ["dystopian", "political satire", "classic"]
}, {
    "title": "To Kill a Mockingbird",
    "author": "Harper Lee",
    "publish_date": "1960-07-11",
    "content":
    "Novel by Harper Lee published in 1960. Instantly successful, widely read in high schools and middle schools in the United States.",
    "tags": ["classic", "drama", "legal"]
}]


# --- Main Script ---
def main():
    try:
        es = Elasticsearch(
            hosts=[{
                'host': host,
                'port': port,
                'scheme': 'https',
            }],
            basic_auth=(username, password),
            verify_certs=False,
            ssl_show_warn=False,
        )

        if not es.ping():
            print(
                "Could not connect to Elasticsearch. Please check your host, port, and credentials."
            )
            return

        if not es.indices.exists(index=index_name):
            response = es.indices.create(
                index=index_name,
                body=index_body,
                ignore=400
            )  # ignore=400 to prevent error if already exists (though we check above)
            print(f"Index '{index_name}' created successfully.")
            print("Response:", response)

        print(f"Adding documents to index '{index_name}'...")
        for i, doc in enumerate(documents):
            response = es.index(index=index_name, document=doc)
            print(f"Document {i+1} added. ID: {response['_id']}")

        query_term = {
            "query": {
                "term": {
                    "content": "fiction"
                }
            }
        }
        response_term = es.search(index=index_name, body=query_term)
        print(f"Found {response_term['hits']['total']['value']} documents.")
        for hit in response_term['hits']['hits']:
            print(f"  ID: {hit['_id']}, Title: {hit['_source']['title']}, Tags: {hit['_source']['tags']}")
        print("-" * 30 + "\n")
    except ConnectionError as ce:
        print(
            f"Connection error: Could not connect to Elasticsearch. Error: {ce}"
        )
        print("Please ensure Elasticsearch is running and accessible.")
    except ApiError as ae:
        print(f"Elasticsearch API error: {ae}")
        print("There might be an issue with the documents or permissions.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")


if __name__ == "__main__":
    main()
