import uuid

class DataPoint:
    def __init__(self, field_names: list):
        self.field_names = field_names
        self.data = {name: None for name in field_names}
        self.id = str(uuid.uuid4())

    def set_value(self, field_name: str, value):
        if field_name in self.field_names:
            self.data[field_name] = value

    def get_value(self, field_name: str):
        if field_name in self.field_names:
            return self.data.get(field_name)
        else:
            raise ValueError(f"Field '{field_name}' not found")

    def search_field(self, value):
        for field_name, field_value in self.data.items():
            if field_value == value:
                return field_name
        raise ValueError(f"Value '{value}' not found")


class Database:
    def __init__(self):
        self.data_points = []
        self.relations = {}

    def add_datapoint(self, datapoint: DataPoint):
        self.data_points.append(datapoint)

    def link_entities(self, datapoint_id_1: str, datapoint_id_2: str, relation_name: str):
        if datapoint_id_1 in self.relations:
            self.relations[datapoint_id_1][relation_name] = datapoint_id_2
        else:
            self.relations[datapoint_id_1] = {relation_name: datapoint_id_2}

    def search_datapoint(self, search_criteria: dict):
        for datapoint in self.data_points:
            match_found = all(datapoint.get_value(field_name) == value for field_name, value in search_criteria.items())
            if match_found:
                return datapoint
        raise ValueError("No matching datapoint found")


# Example usage:
def create_datapoint(field_names):
    datapoint = DataPoint(field_names)
    for field in field_names:
        value = input(f"Please enter your {field}: ")
        datapoint.set_value(field, value)
    return datapoint

# Usage:
field_names = ["name", "age", "city"]
datapoint = create_datapoint(field_names)
db=Database()
db.add_datapoint(datapoint)
#db.link_entities(datapoint1.id, datapoint2.id, "friends")

search_criteria = {"city": "Los Angeles"}
result = db.search_datapoint(search_criteria)
print(result.data)
