import cv2
import face_recognition
import numpy as np
import pickle
import os

# Directory to store face encodings
db_file = "face_encodings.pkl"

# Load existing face encodings
def load_encodings():
    if os.path.exists(db_file):
        with open(db_file, "rb") as f:
            return pickle.load(f)
    return {}

# Save face encodings
def save_encodings(data):
    with open(db_file, "wb") as f:
        pickle.dump(data, f)

# Register a new face
def register_face(name):
    encodings = load_encodings()
    cap = cv2.VideoCapture(0)
    print("[INFO] Position your face in front of the camera...")
    
    while True:
        ret, frame = cap.read()
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        face_locations = face_recognition.face_locations(rgb_frame)
        
        if face_locations:
            face_encoding = face_recognition.face_encodings(rgb_frame, face_locations)[0]
            encodings[name] = face_encoding
            save_encodings(encodings)
            print(f"[INFO] Face registered for {name}")
            break
        
        cv2.imshow("Registering Face", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    cap.release()
    cv2.destroyAllWindows()

# Recognize a face
def recognize_face():
    encodings = load_encodings()
    known_faces = list(encodings.values())
    known_names = list(encodings.keys())
    
    cap = cv2.VideoCapture(0)
    print("[INFO] Scanning faces...")
    
    while True:
        ret, frame = cap.read()
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        face_locations = face_recognition.face_locations(rgb_frame)
        face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)
        
        for face_encoding, face_location in zip(face_encodings, face_locations):
            matches = face_recognition.compare_faces(known_faces, face_encoding)
            name = "Unknown"
            
            if True in matches:
                match_index = matches.index(True)
                name = known_names[match_index]
                print(f"[ACCESS GRANTED] Welcome, {name}!")
            else:
                print("[ACCESS DENIED] Unrecognized face!")
            
            top, right, bottom, left = face_location
            color = (0, 255, 0) if name != "Unknown" else (0, 0, 255)
            cv2.rectangle(frame, (left, top), (right, bottom), color, 2)
            cv2.putText(frame, name, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, color, 2)
        
        cv2.imshow("Face Recognition", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    cap.release()
    cv2.destroyAllWindows()

# Main menu
def main():
    while True:
        choice = input("1. Register Face\n2. Recognize Face\n3. Exit\nEnter choice: ")
        if choice == "1":
            name = input("Enter your name: ")
            register_face(name)
        elif choice == "2":
            recognize_face()
        elif choice == "3":
            break
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()
