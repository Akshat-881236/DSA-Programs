import graphviz

# Define the ER diagram for Akshat Network Hub ecosystem
er = graphviz.Digraph('AkshatNetworkHub_ERD', format='png')

# Entities
entities = {
    "User": ["UserID (PK)", "Name", "Role", "Email", "ProfileURL"],
    "Project": ["ProjectID (PK)", "Name", "Description", "RepoURL", "Category"],
    "Certificate": ["CertID (PK)", "Title", "Issuer", "IssuedTo (FK)", "IssueDate", "FileURL"],
    "Course": ["CourseID (PK)", "Name", "Description", "Provider", "Category"],
    "Quiz": ["QuizID (PK)", "Title", "CourseID (FK)", "TotalQuestions", "CreatedBy (FK)"],
    "Question": ["QuestionID (PK)", "QuizID (FK)", "Text", "Type"],
    "QuizAttempt": ["AttemptID (PK)", "UserID (FK)", "QuizID (FK)", "Score", "AttemptDate"],
    "SitemapRecord": ["RecordID (PK)", "URL", "LastModified", "Priority", "ChangeFreq"],
    "TrackerLog": ["LogID (PK)", "EventType", "ProjectID (FK)", "Timestamp", "Meta"],
    "Asset": ["AssetID (PK)", "FileName", "FileType", "FileURL", "AssociatedEntity", "EntityID"]
}

# Add nodes
for entity, fields in entities.items():
    label = entity + "|" + "\\l".join(fields) + "\\l"
    er.node(entity, label=label, shape="record")

# Relationships (simplified)
relations = [
    ("User", "Certificate", "1", "N", "has"),
    ("User", "QuizAttempt", "1", "N", "takes"),
    ("Quiz", "Question", "1", "N", "contains"),
    ("Course", "Quiz", "1", "N", "includes"),
    ("Project", "TrackerLog", "1", "N", "logs"),
    ("Certificate", "Asset", "1", "1", "has"),
    ("Project", "Asset", "1", "N", "contains"),
    ("QuizAttempt", "Quiz", "N", "1", "for")
]

# Add edges
for src, dst, card1, card2, label in relations:
    er.edge(src, dst, label=f"{card1}:{card2} {label}")

# Render diagram
output_path = "/mnt/data/AkshatNetworkHub_ER_Model"
er.render(output_path)

output_path + ".png"