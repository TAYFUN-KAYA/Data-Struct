
import React from 'react';
import Navi from './Navi';
import ProductList from './ProductList';
import CategoryList from './CategoryList';
import {Container,Row,Col} from 'reactstrap';

function App() {
  let categoryinfo={title:"CategooryList",durumu:"Aktif"};
  let productinfo={title:"ProducctList",durumu:"Pasif"};
  return (
    <div>

      <Container>
        <Row>
          <Navi/>
        </Row>
        <Row>

          <Col xs="3">
            <CategoryList info={categoryinfo} />
          </Col>
          <Col xs="9">
            <ProductList info={productinfo} />
          </Col>

          
          
        </Row>
      </Container>


      
      
      
    </div>
  );
}

export default App;
