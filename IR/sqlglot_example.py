import sqlglot
from sqlglot.optimizer import optimize


result = sqlglot.transpile("SELECT EPOCH_MS(1618088028295)", read="duckdb", write="hive")
print(result)

result = sqlglot.transpile("SELECT STRFTIME(x, '%y-%-m-%S')", read="duckdb", write="hive")
print(result)

result = sqlglot.parse_one("""
SELECT x.A OR (x.B OR (C AND D))
FROM x
INNER JOIN y
WHERE x.A = y.A AND
    Z = date '2021-01-01' + INTERVAL '1' month OR 1 = 0
""")

print(result)

schema = {
    "x": {"A": "INT", "B": "INT", "C": "INT", "D": "INT", "Z": "STRING"},
    "y": {"A": "INT", "B": "INT"},
}

result = optimize(
    result,
    schema=schema)
print(optimize(result))
