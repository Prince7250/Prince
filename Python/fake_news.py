import torch
from transformers import BertTokenizer, BertForSequenceClassification
from sklearn.preprocessing import LabelEncoder

model_name = "bert-base-uncased"
tokenizer = BertTokenizer.from_pretrained(model_name)

try:
    model = BertForSequenceClassification.from_pretrained(model_name, num_labels=2)
except Exception as e:
    print(f"Error loading model: {e}")
    model = None

def predict_fake_news(text):
    if model is None:
        return "Model not loaded", 0.0
    
    inputs = tokenizer(text, return_tensors="pt", truncation=True, padding=True, max_length=128)
    
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model.to(device)
    inputs = {key: val.to(device) for key, val in inputs.items()}
    
    model.eval()
    
    with torch.no_grad():
        outputs = model(**inputs)
        logits = outputs.logits
    
    prediction = torch.argmax(logits, dim=1).item()
    
    if prediction == 1:
        return "Likely Fake", logits[0][1].item()
    else:
        return "Likely Real", logits[0][0].item()

sample_texts = [
    "Scientists discover new species in Pacific Ocean",
    "Aliens invade Florida, government hides truth!",
    "Government announces new policy to reduce carbon emissions",
    "Celebrity found living on Mars, NASA confirms!",
    "New study shows coffee reduces risk of heart disease",
    "Secret potion found to make people immortal, experts shocked!"
]

for text in sample_texts:
    label, confidence = predict_fake_news(text)
    print(f"Text: {text}")
    print(f"Prediction: {label} (Confidence: {confidence:.2f})")
    print("-" * 50)

def check_source_credibility(url):
    trusted_domains = ["reuters.com", "bbc.com", "nytimes.com"]
    for domain in trusted_domains:
        if domain in url.lower():
            return "Trusted Source"
    return "Unknown/Untrusted Source"

sample_urls = [
    "https://unknownblog.xyz/aliens-invade",
    "https://www.bbc.com/news/science-environment-123456",
    "https://fake-news-site.net/breaking-secret-potion-discovered"
]

for url in sample_urls:
    source_result = check_source_credibility(url)
    print(f"Source: {url}")
    print(f"Source Credibility: {source_result}")
    print("-" * 50)