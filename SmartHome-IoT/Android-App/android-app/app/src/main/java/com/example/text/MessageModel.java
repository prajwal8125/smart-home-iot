package com.example.text;   // ← must match YOUR package name

public class MessageModel {

    public String text;
    public long timestamp;

    // Required empty constructor for Firebase
    public MessageModel() {}

    public MessageModel(String text, long timestamp) {
        this.text = text;
        this.timestamp = timestamp;
    }
}