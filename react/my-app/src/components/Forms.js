
import { useState, useEffect, useReducer } from "react"
import axios from 'axios';

const Forms = () => {
    const [forms, setForms] = useState({
        title: "", author: "", description: "", reading_time: ""
    });

    let name, value;

    let baseURL = "https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs"

    const handleInputs = (e) => {
        e.preventDefault();

        name = e.target.name;
        value = e.target.value;
        console.log(name, value)
        setForms({
            ...forms,
            [name]: value
        });

    };

    const handleSubmit = (e) => {
        e.preventDefault()
        console.log("27", forms)
        axios.post(baseURL, forms, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then(console.log());


        console.log(e);

    }

    console.log(forms)

    return (

        // <form className='form-inline' onSubmit={setFormData}>
        <form >
            <div class="mb-3 row">
                <label for="inputTitle" class="col-sm-2 col-form-label">TITLE</label>
                <div class="col-sm-10">
                    {/* <input type="text" placeholder="Enter a title" class="form-control" id="inputTitle"/> */}

                    <input type="text" value={forms.title} onChange={handleInputs} placeholder="Enter a title" name="title" class="form-control" id="inputTitle" />
                </div>
            </div>

            <div class="mb-3 row">
                <label for="inputAuthor" class="col-sm-2 col-form-label">AUTHOR</label>
                <div class="col-sm-10">
                    <input type="text" value={forms.author} onChange={handleInputs} placeholder="Author Name" name="author" class="form-control" id="inputAuthor" />
                </div>
            </div>

            <div class="mb-3 row">
                <label for="inputDescription" class="col-sm-2 col-form-label">DESCRIBE</label>
                <div class="col-sm-10">
                    <input type="text" value={forms.describe} onChange={handleInputs} placeholder="Blog Description" name="description" class="form-control" id="inputDescription" />
                </div>
            </div>

            <div class="mb-3 row">
                <label for="inputReadTime" class="col-sm-2 col-form-label">READ TIME</label>
                <div class="col-sm-10">
                    <input type="number" value={forms.reading_time} onChange={handleInputs} placeholder="No of times read" name="reading_time" class="form-control" id="inputReading_Time" />
                </div>
            </div>

            <input type="submit" onClick={handleSubmit} value="Submit" />

        </form>

    )
}

export default Forms 
