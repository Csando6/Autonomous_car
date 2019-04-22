package com.example.harshapodapati.arduinocar;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button)findViewById(R.id.button);
        button.setOnClickListener( new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                openActivity2();
            }//end of onClick function

        }//end of OnClickListener function

        );//end of button.setOnClickListener

    }//end of onCreate function

    public void openActivity2()
    {
        Intent intent = new Intent(this, SendDataFromArduino.class);
        startActivity(intent);
    }//end of openActivity2 function

}//end of MainActivity class
