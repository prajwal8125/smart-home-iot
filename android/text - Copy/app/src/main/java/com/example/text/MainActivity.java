package com.example.text;

import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class MainActivity extends AppCompatActivity {

    // 4 Switches
    Switch switch1, switch2, switch3, switch4;

    // 4 Status TextViews
    TextView tv1, tv2, tv3, tv4;

    // Firebase references
    DatabaseReference relay1Ref, relay2Ref, relay3Ref, relay4Ref;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Link UI
        switch1 = findViewById(R.id.switch1);
        switch2 = findViewById(R.id.switch2);
        switch3 = findViewById(R.id.switch3);
        switch4 = findViewById(R.id.switch4);

        tv1 = findViewById(R.id.tv1);
        tv2 = findViewById(R.id.tv2);
        tv3 = findViewById(R.id.tv3);
        tv4 = findViewById(R.id.tv4);

        // Firebase references
        relay1Ref = FirebaseDatabase.getInstance().getReference("relay1");
        relay2Ref = FirebaseDatabase.getInstance().getReference("relay2");
        relay3Ref = FirebaseDatabase.getInstance().getReference("relay3");
        relay4Ref = FirebaseDatabase.getInstance().getReference("relay4");

        // Switch listeners
        setupSwitch(switch1, tv1, relay1Ref, "Fan");
        setupSwitch(switch2, tv2, relay2Ref, "Light");
        setupSwitch(switch3, tv3, relay3Ref, "AC");
        setupSwitch(switch4, tv4, relay4Ref, "TV");
    }

    private void setupSwitch(Switch sw, TextView tv,
                             DatabaseReference ref, String name) {
        sw.setOnCheckedChangeListener((buttonView, isChecked) -> {
            int value = isChecked ? 1 : 0;

            ref.setValue(value)
                    .addOnSuccessListener(unused -> {
                        // success
                    })
                    .addOnFailureListener(e -> {
                        // failed
                    });

            // Update status text
            if (isChecked) {
                tv.setText(name + ": ON");
                tv.setTextColor(getResources()
                        .getColor(android.R.color.holo_green_dark));
            } else {
                tv.setText(name + ": OFF");
                tv.setTextColor(getResources()
                        .getColor(android.R.color.holo_red_dark));
            }
        });
    }
}